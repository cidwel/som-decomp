; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D13B
boss_lz_controls_dad13b:
    ; backreference count 4, distance 397
    .byte $89, $8C
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
