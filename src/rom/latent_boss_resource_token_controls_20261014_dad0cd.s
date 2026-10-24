; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0CD
boss_lz_controls_dad0cd:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
