; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B16E
boss_lz_controls_dbb16e:
    ; backreference count 3, distance 191
    .byte $80, $BE
    ; literal count 41; subsequent asset bytes excluded
    .byte $28
