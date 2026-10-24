; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0282
boss_lz_controls_db0282:
    ; backreference count 3, distance 754
    .byte $82, $F1
    ; backreference count 4, distance 502
    .byte $91, $F5
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
