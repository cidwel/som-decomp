; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0E76
boss_lz_controls_db0e76:
    ; backreference count 3, distance 1
    .byte $80, $00
    ; backreference count 3, distance 107
    .byte $80, $6A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
