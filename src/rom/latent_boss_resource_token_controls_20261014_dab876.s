; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B876
boss_lz_controls_dab876:
    ; backreference count 3, distance 51
    .byte $80, $32
    ; literal count 36; subsequent asset bytes excluded
    .byte $23
