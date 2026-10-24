; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AAD
boss_lz_controls_db0aad:
    ; backreference count 4, distance 21
    .byte $90, $14
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
