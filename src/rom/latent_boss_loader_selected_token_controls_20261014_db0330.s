; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0330
boss_lz_controls_db0330:
    ; backreference count 4, distance 11
    .byte $90, $0A
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
