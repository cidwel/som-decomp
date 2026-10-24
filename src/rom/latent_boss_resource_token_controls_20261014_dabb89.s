; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB89
boss_lz_controls_dabb89:
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
