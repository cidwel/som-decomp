; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D288
boss_lz_controls_dad288:
    ; backreference count 3, distance 440
    .byte $81, $B7
    ; backreference count 3, distance 141
    .byte $80, $8C
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
