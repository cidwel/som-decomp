; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0DF1
boss_lz_controls_db0df1:
    ; backreference count 27, distance 201
    .byte $B0, $C8
    ; backreference count 29, distance 222
    .byte $B4, $DD
    ; backreference count 66, distance 511
    .byte $FF, $FE
    ; backreference count 65, distance 383
    .byte $FD, $7E
    ; literal count 122; subsequent asset bytes excluded
    .byte $79
