; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0026
boss_lz_controls_db0026:
    ; backreference count 4, distance 43
    .byte $90, $2A
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
