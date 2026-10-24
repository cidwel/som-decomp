; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0395
boss_lz_controls_db0395:
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
