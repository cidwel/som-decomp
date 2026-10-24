; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7F7
boss_lz_controls_dbb7f7:
    ; backreference count 6, distance 57
    .byte $8C, $38
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
