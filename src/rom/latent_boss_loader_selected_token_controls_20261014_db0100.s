; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0100
boss_lz_controls_db0100:
    ; backreference count 4, distance 11
    .byte $90, $0A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
