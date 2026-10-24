; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $94D8
boss_lz_controls_db94d8:
    ; backreference count 5, distance 257
    .byte $A1, $00
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
