; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0922
boss_lz_controls_db0922:
    ; backreference count 5, distance 2399
    .byte $A9, $5E
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
