; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D422
boss_lz_controls_dad422:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
