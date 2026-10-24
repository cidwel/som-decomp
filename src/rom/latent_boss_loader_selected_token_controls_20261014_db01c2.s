; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01C2
boss_lz_controls_db01c2:
    ; backreference count 4, distance 328
    .byte $91, $47
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
