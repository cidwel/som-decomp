; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $94F1
boss_lz_controls_db94f1:
    ; backreference count 5, distance 251
    .byte $A0, $FA
    ; literal count 19; subsequent asset bytes excluded
    .byte $12
