; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBB5
boss_lz_controls_dbbbb5:
    ; backreference count 5, distance 613
    .byte $8A, $64
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
