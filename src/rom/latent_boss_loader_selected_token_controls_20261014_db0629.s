; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0629
boss_lz_controls_db0629:
    ; backreference count 6, distance 1247
    .byte $B4, $DE
    ; backreference count 3, distance 1410
    .byte $85, $81
    ; backreference count 3, distance 553
    .byte $82, $28
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
