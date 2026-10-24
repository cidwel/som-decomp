; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B1E
boss_lz_controls_db0b1e:
    ; backreference count 5, distance 42
    .byte $A0, $29
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
