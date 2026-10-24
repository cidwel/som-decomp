; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BD6
boss_lz_controls_db0bd6:
    ; backreference count 4, distance 29
    .byte $90, $1C
    ; backreference count 4, distance 44
    .byte $90, $2B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
