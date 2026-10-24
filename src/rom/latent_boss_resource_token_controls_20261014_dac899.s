; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C899
boss_lz_controls_dac899:
    ; backreference count 4, distance 560
    .byte $8A, $2F
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
