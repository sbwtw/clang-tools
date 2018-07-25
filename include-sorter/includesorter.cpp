
#include "includesorter.h"

#include <clang/Frontend/CompilerInstance.h>

#include <iostream>
#include <memory>

using namespace std;

PreprocessorCallback::PreprocessorCallback(SourceManager &sm)
    : sourceManager(sm)
{

}

void PreprocessorCallback::InclusionDirective(clang::SourceLocation hashLocation,
                                              const clang::Token &,
                                              StringRef fileName,
                                              bool isAngled,
                                              CharSourceRange filenameRange,
                                              const FileEntry *file,
                                              StringRef searchPath,
                                              StringRef relativePath,
                                              const clang::Module *imported)
{
    if (!sourceManager.isInMainFile(hashLocation))
        return;

    const auto [fileID, offset] = sourceManager.getDecomposedLoc(hashLocation);
    const unsigned line_number = sourceManager.getLineNumber(fileID, offset);

    cout << "got: " << line_number << endl;
}

IncludeSorterAction::IncludeSorterAction()
{

}

bool IncludeSorterAction::BeginInvocation(CompilerInstance &ci)
{
    cout << "begin invocation" << endl;

    return true;
}

bool IncludeSorterAction::BeginSourceFileAction(CompilerInstance &ci)
{
    cout << "begin source file action" << endl;
    auto hooks = std::make_unique<PreprocessorCallback>(ci.getSourceManager());
    ci.getPreprocessor().addPPCallbacks(std::move(hooks));

    return true;
}

void IncludeSorterAction::EndSourceFileAction()
{
    cout << "end source file action" << endl;
}

FrontendAction *IncludeSorterFactory::create()
{
    return new IncludeSorterAction();
}
