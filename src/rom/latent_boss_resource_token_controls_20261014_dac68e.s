; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C68E
boss_lz_controls_dac68e:
    ; backreference count 3, distance 786
    .byte $83, $11
    ; backreference count 4, distance 790
    .byte $8B, $15
    ; literal count 18; subsequent asset bytes excluded
    .byte $11
