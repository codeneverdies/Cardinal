#ifndef CARDINAL_H
#define CARDINAL_H

#include <ntddk.h>
#include <ntifs.h>

#define CARDINAL_MEM_TAG 0x1111

#define DRIVER_OVERRAN_STACK_BUFFER 0xF7
#define KERNEL_MODE_HEAP_CORRUPTION 0x13A

#define KB_REMOVE_PAGES_FLAG_VIRTUAL_ADDRESS 	     0x00000001UL
#define KB_REMOVE_PAGES_FLAG_PHYSICAL_ADDRESS 	     0x00000002UL
#define KB_REMOVE_PAGES_FLAG_ADDITIONAL_RANGES_EXIST 0x80000000UL

typedef struct _KLDR_DATA_TABLE_ENTRY {
    struct _LIST_ENTRY InLoadOrderLinks;                
    VOID* ExceptionTable;                               
    ULONG ExceptionTableSize;                           
    VOID* GpValue;                                      
    struct _NON_PAGED_DEBUG_INFO* NonPagedDebugInfo;    
    VOID* DllBase;                                      
    VOID* EntryPoint;                                   
    ULONG SizeOfImage;                                  
    struct _UNICODE_STRING FullDllName;                 
    struct _UNICODE_STRING BaseDllName;                 
    ULONG Flags;                                        
    USHORT LoadCount;                                   
    union                                               
    {                                                   
        USHORT SignatureLevel : 4;                      
        USHORT SignatureType : 3;                       
        USHORT Frozen : 2;                              
        USHORT HotPatch : 1;                            
        USHORT Unused : 6;                              
        USHORT EntireField;                             
    } u1;                                               
    VOID* SectionPointer;                               
    ULONG CheckSum;                                     
    ULONG CoverageSectionSize;                          
    VOID* CoverageSection;                              
    VOID* LoadedImports;                                
    union                                               
    {                                                   
        VOID* Spare;                                    
        struct _KLDR_DATA_TABLE_ENTRY* NtDataTableEntry;
    };                                                  
    ULONG SizeOfImageNotRounded;                        
    ULONG TimeDateStamp;                                
} _KLDR_DATA_TABLE_ENTRY, *PKLDR_DATA_TABLE_ENTRY;

typedef struct _KBUGCHECK_REMOVE_PAGES {
  PVOID     Context;
  ULONG     Flags;
  ULONG     BugCheckCode;
  ULONG_PTR Address;
  ULONG_PTR Count;
} KBUGCHECK_REMOVE_PAGES, *PKBUGCHECK_REMOVE_PAGES;

#endif // CARDINAL_H