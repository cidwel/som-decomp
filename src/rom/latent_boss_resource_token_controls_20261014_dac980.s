; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C980
boss_lz_controls_dac980:
    ; backreference count 18, distance 605
    .byte $FA, $5C
    ; backreference count 18, distance 1175
    .byte $FC, $96
    ; backreference count 5, distance 1175
    .byte $94, $96
    ; backreference count 6, distance 605
    .byte $9A, $5C
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
