; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0032
boss_lz_controls_db0032:
    ; backreference count 3, distance 19
    .byte $80, $12
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
