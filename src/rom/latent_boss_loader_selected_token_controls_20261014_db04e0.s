; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04E0
boss_lz_controls_db04e0:
    ; backreference count 7, distance 1376
    .byte $C5, $5F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
