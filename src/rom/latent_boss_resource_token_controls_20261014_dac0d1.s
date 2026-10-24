; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0D1
boss_lz_controls_dac0d1:
    ; backreference count 3, distance 561
    .byte $82, $30
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
