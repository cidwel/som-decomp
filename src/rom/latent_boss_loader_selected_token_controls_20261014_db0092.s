; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0092
boss_lz_controls_db0092:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
