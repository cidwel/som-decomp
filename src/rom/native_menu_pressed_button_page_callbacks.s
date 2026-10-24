; Bank C0 near-call targets, button-major then page; docs/ui-native-menu-callback-tables.md.
.setcpu "65816"
.segment "CODE"
.org $3297
native_menu_pressed_button_page_callbacks:
    ; Pressed button position 0; pages 0 through 10.
    .word $3296, $3296, $3296, $3296, $3296, $2BEA, $3078, $3296, $3296, $3296, $3296
    ; Pressed button position 1; pages 0 through 10.
    .word $3296, $3296, $3296, $3296, $3296, $2BEF, $30A2, $3296, $3296, $3296, $3296
    ; Pressed button position 2; pages 0 through 10.
    .word $3296, $3296, $3296, $3296, $3296, $3296, $3134, $3296, $2D50, $3296, $3296
    ; Pressed button position 3; pages 0 through 10.
    .word $3296, $3296, $3296, $3296, $3296, $3296, $3134, $3296, $3296, $2D36, $3296
    ; Pressed button position 4; pages 0 through 10.
    .word $2D27, $2E65, $2EBC, $318E, $2F15, $2BFB, $308D, $2EE0, $2D6F, $2D6F, $2E7D
    ; Pressed button position 5; pages 0 through 10.
    .word $3296, $305A, $306A, $31C2, $3043, $2BF4, $30B7, $305A, $317E, $317E, $2EA2
    ; Pressed button position 6; pages 0 through 10.
    .word $2CBE, $305A, $306A, $31B6, $3043, $2C0F, $300C, $305A, $317E, $317E, $2EA2
    ; Pressed button position 7; pages 0 through 10.
    .word $2D27, $2E65, $2EBC, $31E2, $2F15, $2BFB, $302F, $2EE0, $2D6F, $2D6F, $2E7D
    ; Pressed button position 8; pages 0 through 10.
    .word $2CBE, $2CBE, $2CBE, $3296, $2F41, $2C3C, $3296, $3296, $2DAD, $2DAD, $3296
    ; Pressed button position 9; pages 0 through 10.
    .word $2CF3, $2CF3, $2CF3, $3296, $2F83, $2C59, $3296, $3296, $2DE2, $2DE2, $3296
    ; Pressed button position 10; pages 0 through 10.
    .word $3296, $3296, $3296, $3210, $2FC8, $2C76, $3296, $3296, $2E14, $2E14, $3296
    ; Pressed button position 11; pages 0 through 10.
    .word $3296, $3296, $3296, $3221, $2FEA, $2C9A, $3296, $3296, $2E3D, $2E3D, $3296
