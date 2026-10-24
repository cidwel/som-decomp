; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F08A
boss_lz_controls_daf08a:
    ; backreference count 3, distance 2905
    .byte $8B, $58
    ; literal count 90; subsequent asset bytes excluded
    .byte $59
