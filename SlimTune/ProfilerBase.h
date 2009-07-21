/*
* Copyright (c) 2009 SlimDX Group
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*/

#pragma once

#include "cor.h"
#include "corprof.h"

#define STDMETHOD_IMPL(name,params) STDMETHOD(name)params { return S_OK; }

class ProfilerBase : public ICorProfilerCallback2
{
public:
	ProfilerBase() { }

	STDMETHOD_IMPL(Initialize,(IUnknown *pICorProfilerInfoUnk));
	STDMETHOD_IMPL(Shutdown,());

	STDMETHOD_IMPL(AppDomainCreationStarted,(AppDomainID appDomainID));
	STDMETHOD_IMPL(AppDomainCreationFinished,(AppDomainID appDomainID, HRESULT hrStatus));
	STDMETHOD_IMPL(AppDomainShutdownStarted,(AppDomainID appDomainID));
	STDMETHOD_IMPL(AppDomainShutdownFinished,(AppDomainID appDomainID, HRESULT hrStatus));

	STDMETHOD_IMPL(AssemblyLoadStarted,(AssemblyID assemblyID));
	STDMETHOD_IMPL(AssemblyLoadFinished,(AssemblyID assemblyID, HRESULT hrStatus));
	STDMETHOD_IMPL(AssemblyUnloadStarted,(AssemblyID assemblyID));
	STDMETHOD_IMPL(AssemblyUnloadFinished,(AssemblyID assemblyID, HRESULT hrStatus));

	STDMETHOD_IMPL(ModuleLoadStarted,(ModuleID moduleID));
	STDMETHOD_IMPL(ModuleLoadFinished,(ModuleID moduleID, HRESULT hrStatus));
	STDMETHOD_IMPL(ModuleUnloadStarted,(ModuleID moduleID));
	STDMETHOD_IMPL(ModuleUnloadFinished,(ModuleID moduleID, HRESULT hrStatus));
	STDMETHOD_IMPL(ModuleAttachedToAssembly,(ModuleID moduleID, AssemblyID assemblyID));

	STDMETHOD_IMPL(ClassLoadStarted,(ClassID classID));
	STDMETHOD_IMPL(ClassLoadFinished,(ClassID classID, HRESULT hrStatus));
	STDMETHOD_IMPL(ClassUnloadStarted,(ClassID classID));
	STDMETHOD_IMPL(ClassUnloadFinished,(ClassID classID, HRESULT hrStatus));
	STDMETHOD_IMPL(FunctionUnloadStarted,(FunctionID functionID));

	STDMETHOD_IMPL(JITCompilationStarted,(FunctionID functionID, BOOL fIsSafeToBlock));
	STDMETHOD_IMPL(JITCompilationFinished,(FunctionID functionID, HRESULT hrStatus, BOOL fIsSafeToBlock));
	STDMETHOD_IMPL(JITCachedFunctionSearchStarted,(FunctionID functionID, BOOL *pbUseCachedFunction));
	STDMETHOD_IMPL(JITCachedFunctionSearchFinished,(FunctionID functionID, COR_PRF_JIT_CACHE result));
	STDMETHOD_IMPL(JITFunctionPitched,(FunctionID functionID));
	STDMETHOD_IMPL(JITInlining,(FunctionID callerID, FunctionID calleeID, BOOL *pfShouldInline));

	STDMETHOD_IMPL(ThreadCreated,(ThreadID threadID));
	STDMETHOD_IMPL(ThreadDestroyed,(ThreadID threadID));
	STDMETHOD_IMPL(ThreadAssignedToOSThread,(ThreadID managedThreadID, DWORD osThreadID));

	STDMETHOD_IMPL(RemotingClientInvocationStarted,());
	STDMETHOD_IMPL(RemotingClientSendingMessage,(GUID *pCookie, BOOL fIsAsync));
	STDMETHOD_IMPL(RemotingClientReceivingReply,(GUID *pCookie, BOOL fIsAsync));
	STDMETHOD_IMPL(RemotingClientInvocationFinished,());
	STDMETHOD_IMPL(RemotingServerReceivingMessage,(GUID *pCookie, BOOL fIsAsync));
	STDMETHOD_IMPL(RemotingServerInvocationStarted,());
	STDMETHOD_IMPL(RemotingServerInvocationReturned,());
	STDMETHOD_IMPL(RemotingServerSendingReply,(GUID *pCookie, BOOL fIsAsync));

	STDMETHOD_IMPL(UnmanagedToManagedTransition,(FunctionID functionID, COR_PRF_TRANSITION_REASON reason));
	STDMETHOD_IMPL(ManagedToUnmanagedTransition,(FunctionID functionID, COR_PRF_TRANSITION_REASON reason));

	STDMETHOD_IMPL(RuntimeSuspendStarted,(COR_PRF_SUSPEND_REASON suspendReason));
	STDMETHOD_IMPL(RuntimeSuspendFinished,());
	STDMETHOD_IMPL(RuntimeSuspendAborted,());
	STDMETHOD_IMPL(RuntimeResumeStarted,());
	STDMETHOD_IMPL(RuntimeResumeFinished,());
	STDMETHOD_IMPL(RuntimeThreadSuspended,(ThreadID threadid));
	STDMETHOD_IMPL(RuntimeThreadResumed,(ThreadID threadid));

	STDMETHOD_IMPL(MovedReferences,(ULONG cmovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[]));
	STDMETHOD_IMPL(ObjectAllocated,(ObjectID objectID, ClassID classID));
	STDMETHOD_IMPL(ObjectsAllocatedByClass,(ULONG classCount, ClassID classIDs[], ULONG objects[]));
	STDMETHOD_IMPL(ObjectReferences,(ObjectID objectID, ClassID classID, ULONG cObjectRefs, ObjectID objectRefIDs[]));
	STDMETHOD_IMPL(RootReferences,(ULONG cRootRefs, ObjectID rootRefIDs[]));

	STDMETHOD_IMPL(ExceptionThrown,(ObjectID thrownObjectID));
	STDMETHOD_IMPL(ExceptionSearchFunctionEnter,(FunctionID functionID));
	STDMETHOD_IMPL(ExceptionSearchFunctionLeave,());
	STDMETHOD_IMPL(ExceptionSearchFilterEnter,(FunctionID functionID));
	STDMETHOD_IMPL(ExceptionSearchFilterLeave,());
	STDMETHOD_IMPL(ExceptionSearchCatcherFound,(FunctionID functionID));
	STDMETHOD_IMPL(ExceptionCLRCatcherFound,());
	STDMETHOD_IMPL(ExceptionCLRCatcherExecute,());
	STDMETHOD_IMPL(ExceptionOSHandlerEnter,(FunctionID functionID));
	STDMETHOD_IMPL(ExceptionOSHandlerLeave,(FunctionID functionID));
	STDMETHOD_IMPL(ExceptionUnwindFunctionEnter,(FunctionID functionID));
	STDMETHOD_IMPL(ExceptionUnwindFunctionLeave,());
	STDMETHOD_IMPL(ExceptionUnwindFinallyEnter,(FunctionID functionID));
	STDMETHOD_IMPL(ExceptionUnwindFinallyLeave,());
	STDMETHOD_IMPL(ExceptionCatcherEnter,(FunctionID functionID, ObjectID objectID));
	STDMETHOD_IMPL(ExceptionCatcherLeave,());

	STDMETHOD_IMPL(COMClassicVTableCreated,(ClassID wrappedClassID, REFGUID implementedIID, void *pVTable, ULONG cSlots));
	STDMETHOD_IMPL(COMClassicVTableDestroyed,(ClassID wrappedClassID, REFGUID implementedIID, void *pVTable));

	//ICorProfiler2Callback section
	STDMETHOD_IMPL(ThreadNameChanged,(ThreadID threadId, ULONG cchName, WCHAR name[]));

	STDMETHOD_IMPL(GarbageCollectionStarted,(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason));
	STDMETHOD_IMPL(SurvivingReferences,(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[]));
	STDMETHOD_IMPL(GarbageCollectionFinished,());
	STDMETHOD_IMPL(FinalizeableObjectQueued,(DWORD finalizerFlags, ObjectID objectID));
	STDMETHOD_IMPL(RootReferences2,(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[]));

	STDMETHOD_IMPL(HandleCreated,(GCHandleID handleId, ObjectID initialObjectId));
	STDMETHOD_IMPL(HandleDestroyed,(GCHandleID handleId));
};
