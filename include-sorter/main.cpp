

#include "includesorter.h"

#include <iostream>

using namespace std;

using namespace clang;
using namespace clang::tooling;
using namespace llvm;

int main(int argc, const char *argv[])
{
    llvm::cl::OptionCategory includeSorterCategory("test");
    CommonOptionsParser optionsParser(argc, argv, includeSorterCategory);
    ClangTool Tool(optionsParser.getCompilations(),
                   optionsParser.getSourcePathList());

    return Tool.run(new IncludeSorterFactory());
}
