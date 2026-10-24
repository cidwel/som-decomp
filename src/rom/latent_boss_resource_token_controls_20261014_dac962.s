; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C962
boss_lz_controls_dac962:
    ; backreference count 9, distance 1179
    .byte $B4, $9A
    ; backreference count 3, distance 598
    .byte $82, $55
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
