; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-cold-menu-bridge-source.md.
.setcpu "65816"
.smart
.a8
.i16

enter_boot_menu_caller_from_public_alias = $0089

.segment "CODE"
.org $0009
public_boot_menu_caller_alias:
    jmp enter_boot_menu_caller_from_public_alias
