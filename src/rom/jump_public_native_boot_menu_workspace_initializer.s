; docs/ui-native-boot-workspace-aliases.md
.setcpu "65816"
.segment "CODE"
.org $0000
jump_public_native_boot_menu_workspace_initializer:
    jmp $0080
