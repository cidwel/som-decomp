; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AD3
boss_lz_controls_db0ad3:
    ; backreference count 8, distance 5
    .byte $D0, $04
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
