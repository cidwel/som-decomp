; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0233
boss_lz_controls_db0233:
    ; backreference count 6, distance 444
    .byte $B1, $BB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
