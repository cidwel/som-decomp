; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00F0
boss_lz_controls_db00f0:
    ; backreference count 3, distance 124
    .byte $80, $7B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
