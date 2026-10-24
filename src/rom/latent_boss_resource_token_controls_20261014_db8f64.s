; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $8F64
boss_lz_controls_db8f64:
    ; backreference count 4, distance 15
    .byte $90, $0E
    ; literal count 93; subsequent asset bytes excluded
    .byte $5C
