; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D30F
boss_lz_controls_dad30f:
    ; backreference count 3, distance 767
    .byte $82, $FE
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
