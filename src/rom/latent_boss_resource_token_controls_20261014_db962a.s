; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $962A
boss_lz_controls_db962a:
    ; backreference count 6, distance 1904
    .byte $B7, $6F
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
