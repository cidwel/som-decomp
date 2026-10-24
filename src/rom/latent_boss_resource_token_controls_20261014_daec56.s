; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC56
boss_lz_controls_daec56:
    ; backreference count 3, distance 697
    .byte $82, $B8
    ; backreference count 6, distance 774
    .byte $B3, $05
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
