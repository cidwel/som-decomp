; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04CA
boss_lz_controls_db04ca:
    ; backreference count 7, distance 9
    .byte $C0, $08
    ; backreference count 7, distance 1322
    .byte $C5, $29
    ; backreference count 6, distance 644
    .byte $B2, $83
    ; backreference count 8, distance 1558
    .byte $D6, $15
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
