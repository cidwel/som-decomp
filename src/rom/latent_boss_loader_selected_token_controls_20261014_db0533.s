; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0533
boss_lz_controls_db0533:
    ; backreference count 4, distance 65
    .byte $90, $40
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
