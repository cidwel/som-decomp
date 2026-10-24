; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AF81
boss_lz_controls_dbaf81:
    ; backreference count 3, distance 419
    .byte $81, $A2
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
