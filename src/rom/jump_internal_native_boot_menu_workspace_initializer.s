; docs/ui-native-boot-workspace-aliases.md
.setcpu "65816"
.segment "CODE"
.org $0080
jump_internal_native_boot_menu_workspace_initializer:
    jmp $0E40
