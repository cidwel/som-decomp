; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D90B
boss_lz_controls_dad90b:
    ; backreference count 3, distance 530
    .byte $82, $11
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
