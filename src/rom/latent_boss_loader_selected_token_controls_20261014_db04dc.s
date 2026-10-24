; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04DC
boss_lz_controls_db04dc:
    ; backreference count 7, distance 1433
    .byte $C5, $98
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
