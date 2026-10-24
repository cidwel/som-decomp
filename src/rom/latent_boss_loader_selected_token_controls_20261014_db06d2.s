; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06D2
boss_lz_controls_db06d2:
    ; backreference count 4, distance 1020
    .byte $93, $FB
    ; backreference count 3, distance 1642
    .byte $86, $69
    ; backreference count 5, distance 1755
    .byte $A6, $DA
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
