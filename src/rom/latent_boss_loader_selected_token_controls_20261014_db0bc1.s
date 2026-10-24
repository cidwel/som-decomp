; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BC1
boss_lz_controls_db0bc1:
    ; backreference count 4, distance 1376
    .byte $95, $5F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
