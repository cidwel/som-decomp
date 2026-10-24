; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBA6
boss_lz_controls_dacba6:
    ; backreference count 3, distance 191
    .byte $80, $BE
    ; literal count 19; subsequent asset bytes excluded
    .byte $12
