; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6AA
boss_lz_controls_dbd6aa:
    ; backreference count 12, distance 379
    .byte $A5, $7A
    ; literal count 34; subsequent asset bytes excluded
    .byte $21
