; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0335
boss_lz_controls_db0335:
    ; backreference count 5, distance 12
    .byte $A0, $0B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
