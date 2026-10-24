; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B0EE
boss_lz_controls_dbb0ee:
    ; backreference count 25, distance 838
    .byte $DB, $45
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
