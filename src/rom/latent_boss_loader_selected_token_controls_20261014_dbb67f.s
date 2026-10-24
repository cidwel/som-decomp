; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B67F
boss_lz_controls_dbb67f:
    ; backreference count 6, distance 59
    .byte $8C, $3A
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
