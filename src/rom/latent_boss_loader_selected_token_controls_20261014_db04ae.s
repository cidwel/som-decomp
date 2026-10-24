; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04AE
boss_lz_controls_db04ae:
    ; backreference count 7, distance 1142
    .byte $C4, $75
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
