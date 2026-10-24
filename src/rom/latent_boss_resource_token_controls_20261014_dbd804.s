; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D804
boss_lz_controls_dbd804:
    ; backreference count 3, distance 310
    .byte $81, $35
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
