; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B09
boss_lz_controls_db0b09:
    ; backreference count 5, distance 84
    .byte $A0, $53
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
