; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D5CE
boss_lz_controls_dad5ce:
    ; backreference count 3, distance 123
    .byte $80, $7A
    ; literal count 33; subsequent asset bytes excluded
    .byte $20
