; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AA4
boss_lz_controls_db0aa4:
    ; backreference count 5, distance 33
    .byte $A0, $20
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
