; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B44
boss_lz_controls_db0b44:
    ; backreference count 5, distance 920
    .byte $A3, $97
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
