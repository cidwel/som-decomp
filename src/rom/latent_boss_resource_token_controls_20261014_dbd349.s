; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D349
boss_lz_controls_dbd349:
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
