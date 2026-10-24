; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A334
boss_lz_controls_dba334:
    ; backreference count 3, distance 21
    .byte $80, $14
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
