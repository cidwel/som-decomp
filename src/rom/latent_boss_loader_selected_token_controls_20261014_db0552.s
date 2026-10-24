; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0552
boss_lz_controls_db0552:
    ; backreference count 7, distance 16
    .byte $C0, $0F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
