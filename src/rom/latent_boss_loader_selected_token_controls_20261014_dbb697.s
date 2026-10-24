; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B697
boss_lz_controls_dbb697:
    ; backreference count 5, distance 283
    .byte $89, $1A
    ; backreference count 3, distance 45
    .byte $80, $2C
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
