; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C98B
boss_lz_controls_dac98b:
    ; backreference count 4, distance 605
    .byte $8A, $5C
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
