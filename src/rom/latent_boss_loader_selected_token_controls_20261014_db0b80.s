; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B80
boss_lz_controls_db0b80:
    ; backreference count 4, distance 29
    .byte $90, $1C
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
