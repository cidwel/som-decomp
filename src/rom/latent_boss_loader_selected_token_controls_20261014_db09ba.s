; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09BA
boss_lz_controls_db09ba:
    ; backreference count 5, distance 2809
    .byte $AA, $F8
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
