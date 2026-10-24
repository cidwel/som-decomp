; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B96
boss_lz_controls_db0b96:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
