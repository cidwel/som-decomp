; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0879
boss_lz_controls_db0879:
    ; backreference count 3, distance 1388
    .byte $85, $6B
    ; backreference count 3, distance 49
    .byte $80, $30
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
