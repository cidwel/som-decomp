; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BC5
boss_lz_controls_db0bc5:
    ; backreference count 6, distance 14
    .byte $B0, $0D
    ; backreference count 9, distance 30
    .byte $E0, $1D
    ; backreference count 7, distance 46
    .byte $C0, $2D
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
