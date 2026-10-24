; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0442
boss_lz_controls_db0442:
    ; backreference count 4, distance 65
    .byte $90, $40
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
