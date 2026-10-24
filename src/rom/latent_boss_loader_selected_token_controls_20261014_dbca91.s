; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA91
boss_lz_controls_dbca91:
    ; backreference count 4, distance 53
    .byte $90, $34
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
