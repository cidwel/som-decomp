; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8A9
boss_lz_controls_dac8a9:
    ; backreference count 3, distance 560
    .byte $82, $2F
    ; backreference count 3, distance 1144
    .byte $84, $77
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
