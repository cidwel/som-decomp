; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF78
boss_lz_controls_dadf78:
    ; backreference count 8, distance 219
    .byte $A8, $DA
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
