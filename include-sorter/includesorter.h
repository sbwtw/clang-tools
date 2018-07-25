
#ifndef __INCLUDE_SORTER_H_
#define __INCLUDE_SORTER_H_

#include <clang/Tooling/Tooling.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>

using namespace clang;
using namespace clang::tooling;
using namespace llvm;

class PreprocessorCallback : public PPCallbacks
{
public:
    explicit PreprocessorCallback(SourceManager &sm);

    void InclusionDirective(clang::SourceLocation hashLocation,
                            const clang::Token &,
                            StringRef fileName,
                            bool isAngled,
                            CharSourceRange range,
                            const FileEntry *,
                            StringRef searchPath,
                            StringRef relativePath,
                            const clang::Module *imported) override;

private:
    const SourceManager &sourceManager;
};

class IncludeSorterAction : public PreprocessOnlyAction
{
public:
    explicit IncludeSorterAction();

    bool BeginInvocation(CompilerInstance &ci) override;
    bool BeginSourceFileAction(CompilerInstance &ci) override;
    void EndSourceFileAction() override;
};

class IncludeSorterFactory : public FrontendActionFactory
{
public:
    FrontendAction *create() override;
};

#endif // __INCLUDE_SORTER_H_