; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D4D9
boss_lz_controls_dad4d9:
    ; backreference count 3, distance 1400
    .byte $85, $77
    ; literal count 34; subsequent asset bytes excluded
    .byte $21
