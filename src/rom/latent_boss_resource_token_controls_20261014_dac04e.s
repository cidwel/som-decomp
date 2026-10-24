; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C04E
boss_lz_controls_dac04e:
    ; backreference count 7, distance 759
    .byte $92, $F6
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
