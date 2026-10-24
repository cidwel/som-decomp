; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0432
boss_lz_controls_db0432:
    ; backreference count 6, distance 28
    .byte $B0, $1B
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
