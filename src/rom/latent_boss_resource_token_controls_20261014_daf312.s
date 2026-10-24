; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F312
boss_lz_controls_daf312:
    ; backreference count 3, distance 3574
    .byte $8D, $F5
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
