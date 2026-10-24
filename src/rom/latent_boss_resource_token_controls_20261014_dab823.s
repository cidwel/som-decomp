; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B823
boss_lz_controls_dab823:
    ; backreference count 3, distance 89
    .byte $80, $58
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
