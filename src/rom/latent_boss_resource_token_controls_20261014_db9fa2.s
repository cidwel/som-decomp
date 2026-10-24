; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9FA2
boss_lz_controls_db9fa2:
    ; backreference count 4, distance 1185
    .byte $8C, $A0
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
