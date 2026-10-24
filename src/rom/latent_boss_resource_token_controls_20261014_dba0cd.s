; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A0CD
boss_lz_controls_dba0cd:
    ; backreference count 3, distance 928
    .byte $83, $9F
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
