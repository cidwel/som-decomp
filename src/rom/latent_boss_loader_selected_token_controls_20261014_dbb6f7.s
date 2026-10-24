; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6F7
boss_lz_controls_dbb6f7:
    ; backreference count 4, distance 449
    .byte $85, $C0
    ; backreference count 3, distance 802
    .byte $83, $21
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
