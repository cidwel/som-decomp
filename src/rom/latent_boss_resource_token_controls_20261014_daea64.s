; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA64
boss_lz_controls_daea64:
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
