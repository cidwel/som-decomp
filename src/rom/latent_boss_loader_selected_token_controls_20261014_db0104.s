; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0104
boss_lz_controls_db0104:
    ; backreference count 3, distance 161
    .byte $80, $A0
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
