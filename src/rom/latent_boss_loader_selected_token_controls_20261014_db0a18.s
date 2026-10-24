; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A18
boss_lz_controls_db0a18:
    ; backreference count 4, distance 8
    .byte $90, $07
    ; backreference count 9, distance 1350
    .byte $E5, $45
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
