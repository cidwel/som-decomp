; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8A6
boss_lz_controls_dab8a6:
    ; backreference count 3, distance 598
    .byte $82, $55
    ; backreference count 4, distance 646
    .byte $86, $85
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
