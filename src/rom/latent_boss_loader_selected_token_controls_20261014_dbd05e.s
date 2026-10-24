; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D05E
boss_lz_controls_dbd05e:
    ; backreference count 3, distance 265
    .byte $81, $08
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
