; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0109
boss_lz_controls_db0109:
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
