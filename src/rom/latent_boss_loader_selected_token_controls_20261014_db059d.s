; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $059D
boss_lz_controls_db059d:
    ; backreference count 7, distance 9
    .byte $C0, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
