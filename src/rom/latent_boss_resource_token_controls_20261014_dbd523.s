; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D523
boss_lz_controls_dbd523:
    ; backreference count 3, distance 82
    .byte $80, $51
    ; backreference count 34, distance 115
    .byte $FC, $72
    ; backreference count 34, distance 115
    .byte $FC, $72
    ; backreference count 6, distance 115
    .byte $8C, $72
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
