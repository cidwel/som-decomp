; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C1ED
boss_lz_controls_dac1ed:
    ; backreference count 3, distance 788
    .byte $83, $13
    ; backreference count 4, distance 825
    .byte $87, $38
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
