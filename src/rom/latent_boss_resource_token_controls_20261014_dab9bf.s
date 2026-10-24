; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B9BF
boss_lz_controls_dab9bf:
    ; backreference count 3, distance 311
    .byte $81, $36
    ; literal count 32; subsequent asset bytes excluded
    .byte $1F
