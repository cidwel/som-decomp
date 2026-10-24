; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0237
boss_lz_controls_db0237:
    ; backreference count 5, distance 506
    .byte $A1, $F9
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
