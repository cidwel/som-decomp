; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A5F1
boss_lz_controls_dba5f1:
    ; backreference count 3, distance 276
    .byte $81, $13
    ; backreference count 33, distance 263
    .byte $BD, $06
    ; literal count 21; subsequent asset bytes excluded
    .byte $14
