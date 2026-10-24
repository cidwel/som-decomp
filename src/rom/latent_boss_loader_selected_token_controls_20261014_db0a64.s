; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A64
boss_lz_controls_db0a64:
    ; backreference count 4, distance 1761
    .byte $96, $E0
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
