; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0140
boss_lz_controls_db0140:
    ; backreference count 3, distance 5
    .byte $80, $04
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
