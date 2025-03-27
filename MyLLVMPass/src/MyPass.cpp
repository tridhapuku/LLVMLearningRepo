// Header 

#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

// #include "llvm/IR/Function.h"
// #include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
// #include "llvm/Transforms/IPO/PassManagerBuilder.h"




using namespace llvm;

namespace {
struct MyPass : public FunctionPass {
    static char ID;
    MyPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
        errs() << "Function name: " << F.getName() << "\n";
        return false;
    }
};

// struct MyPass : public PassInfoMixin<MyPass> {
//     PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
//         errs() << "Function name: " << F.getName() << "\n";
//         return PreservedAnalyses::all();
//     }
// };

// extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK llvmGetPassPluginInfo() {
//     return {LLVM_PLUGIN_API_VERSION, "MyPass", LLVM_VERSION_STRING,
//             [](PassBuilder &PB) {
//                 PB.registerPipelineParsingCallback(
//                     [](StringRef Name, FunctionPassManager &FPM, ArrayRef<PassBuilder::PipelineElement>) {
//                         if (Name == "mypass") {
//                             FPM.addPass(MyPass());
//                             return true;
//                         }
//                         return false;
//                     });
//             }};
// }
}

char MyPass::ID = 0;
// static RegisterPass<MyPass> X("mypassiname", "My simple pass", false, false);
// static RegisterPass<MyPass> X("mypass", "My simple LLVM pass", false, false);

// static RegisterStandardPasses RegisterMyPass(
//     PassManagerBuilder::EP_EarlyAsPossible,
//     [](const PassManagerBuilder &, legacy::PassManagerBase &PM) {
//         PM.add(new MyPass());
//     });

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &builder,
       legacy::PassManagerBase &PM) { PM.add(new MyPass()); });
