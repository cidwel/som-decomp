; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03EA
boss_lz_controls_db03ea:
    ; backreference count 5, distance 788
    .byte $A3, $13
    ; backreference count 4, distance 681
    .byte $92, $A8
    ; backreference count 4, distance 22
    .byte $90, $15
    ; backreference count 8, distance 30
    .byte $D0, $1D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
