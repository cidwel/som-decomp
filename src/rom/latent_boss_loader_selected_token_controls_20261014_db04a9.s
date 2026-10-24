; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04A9
boss_lz_controls_db04a9:
    ; backreference count 6, distance 7
    .byte $B0, $06
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
