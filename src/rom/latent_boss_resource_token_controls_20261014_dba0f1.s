; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A0F1
boss_lz_controls_dba0f1:
    ; backreference count 6, distance 822
    .byte $9B, $35
    ; backreference count 5, distance 360
    .byte $91, $67
    ; literal count 41; subsequent asset bytes excluded
    .byte $28
