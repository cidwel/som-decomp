; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E4D8
boss_lz_controls_dae4d8:
    ; backreference count 6, distance 591
    .byte $9A, $4E
    ; backreference count 3, distance 71
    .byte $80, $46
    ; backreference count 3, distance 589
    .byte $82, $4C
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A
