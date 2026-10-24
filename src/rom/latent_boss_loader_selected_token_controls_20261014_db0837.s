; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0837
boss_lz_controls_db0837:
    ; backreference count 6, distance 8
    .byte $B0, $07
    ; backreference count 4, distance 1976
    .byte $97, $B7
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
