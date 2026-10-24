; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $048A
boss_lz_controls_db048a:
    ; backreference count 6, distance 1365
    .byte $B5, $54
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
