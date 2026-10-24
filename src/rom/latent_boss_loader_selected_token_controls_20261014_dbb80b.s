; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B80B
boss_lz_controls_dbb80b:
    ; backreference count 3, distance 460
    .byte $81, $CB
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
