; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA4A
boss_lz_controls_dbca4a:
    ; backreference count 3, distance 299
    .byte $81, $2A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
