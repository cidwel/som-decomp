; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0DD
boss_lz_controls_dac0dd:
    ; backreference count 3, distance 75
    .byte $80, $4A
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
