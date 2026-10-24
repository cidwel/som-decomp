; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C538
boss_lz_controls_dac538:
    ; backreference count 3, distance 231
    .byte $80, $E6
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
