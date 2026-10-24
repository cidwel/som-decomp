; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B1A1
boss_lz_controls_dbb1a1:
    ; backreference count 3, distance 677
    .byte $82, $A4
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
