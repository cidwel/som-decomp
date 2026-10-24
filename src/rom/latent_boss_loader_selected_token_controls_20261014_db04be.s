; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04BE
boss_lz_controls_db04be:
    ; backreference count 6, distance 703
    .byte $B2, $BE
    ; backreference count 3, distance 100
    .byte $80, $63
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
