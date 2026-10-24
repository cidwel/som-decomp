; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C764
boss_lz_controls_dac764:
    ; backreference count 5, distance 17
    .byte $90, $10
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
