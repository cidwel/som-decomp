; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D778
boss_lz_controls_dad778:
    ; backreference count 5, distance 6
    .byte $90, $05
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
