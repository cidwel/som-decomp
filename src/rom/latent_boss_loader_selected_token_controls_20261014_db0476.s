; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0476
boss_lz_controls_db0476:
    ; backreference count 4, distance 20
    .byte $90, $13
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
