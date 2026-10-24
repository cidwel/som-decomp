; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $96C5
boss_lz_controls_db96c5:
    ; backreference count 3, distance 2237
    .byte $88, $BC
    ; literal count 21; subsequent asset bytes excluded
    .byte $14
