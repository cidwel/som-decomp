; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D9FF
boss_lz_controls_dad9ff:
    ; backreference count 3, distance 757
    .byte $82, $F4
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
