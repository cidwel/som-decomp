; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA5A
boss_lz_controls_dbca5a:
    ; backreference count 4, distance 53
    .byte $90, $34
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
