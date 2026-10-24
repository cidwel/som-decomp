; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AB5
boss_lz_controls_db0ab5:
    ; backreference count 3, distance 1955
    .byte $87, $A2
    ; backreference count 3, distance 951
    .byte $83, $B6
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
