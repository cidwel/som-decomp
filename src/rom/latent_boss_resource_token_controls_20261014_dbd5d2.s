; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D5D2
boss_lz_controls_dbd5d2:
    ; backreference count 4, distance 72
    .byte $84, $47
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
