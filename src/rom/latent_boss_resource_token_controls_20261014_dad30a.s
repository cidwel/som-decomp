; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D30A
boss_lz_controls_dad30a:
    ; backreference count 3, distance 56
    .byte $80, $37
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
