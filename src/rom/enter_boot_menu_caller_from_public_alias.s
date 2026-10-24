; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-cold-menu-bridge-source.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c000c9 = $00C9

.segment "CODE"
.org $0089
enter_boot_menu_caller_from_public_alias:
    jmp routine_c000c9
