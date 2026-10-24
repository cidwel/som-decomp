; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D84E
boss_lz_controls_dad84e:
    ; backreference count 3, distance 29
    .byte $80, $1C
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
