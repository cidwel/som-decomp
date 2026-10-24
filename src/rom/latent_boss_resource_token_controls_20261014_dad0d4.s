; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0D4
boss_lz_controls_dad0d4:
    ; backreference count 3, distance 19
    .byte $80, $12
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
