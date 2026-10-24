; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D782
boss_lz_controls_dad782:
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
