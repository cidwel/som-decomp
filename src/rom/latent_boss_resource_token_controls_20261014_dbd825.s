; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D825
boss_lz_controls_dbd825:
    ; backreference count 3, distance 23
    .byte $80, $16
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
