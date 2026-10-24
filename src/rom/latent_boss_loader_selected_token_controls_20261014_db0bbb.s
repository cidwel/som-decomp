; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BBB
boss_lz_controls_db0bbb:
    ; backreference count 5, distance 2185
    .byte $A8, $88
    ; backreference count 4, distance 369
    .byte $91, $70
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
