; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03F4
boss_lz_controls_db03f4:
    ; backreference count 6, distance 35
    .byte $B0, $22
    ; backreference count 10, distance 1342
    .byte $F5, $3D
    ; backreference count 4, distance 1048
    .byte $94, $17
    ; backreference count 4, distance 834
    .byte $93, $41
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
