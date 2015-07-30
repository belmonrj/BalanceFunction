AliAnalysisTaskExample *AddTaskExample()
{
  char *name = "Example";
  AliAnalysisManager *aam = AliAnalysisManager::GetAnalysisManager();
  AliAnalysisTaskExample *task = new AliAnalysisTaskExample(name);
  // --- get input and output managers
  AliAnalysisDataContainer *aadci = aam->GetCommonInputContainer();
  AliAnalysisDataContainer *aadco = aam->CreateContainer
    (
     Form("List\%s",name),
     TList::Class(),
     AliAnalysisManager::kOutputContainer,
     Form("Out\%s.root",name)
     );
  // --- add task and connect input and output managers
  aam->AddTask(task);
  aam->ConnectInput(task,0,aadci);
  aam->ConnectOutput(task,1,aadco); // recall class constructor
  // --- return pointer to Task
  return task;
}
