; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $054E
boss_lz_controls_db054e:
    ; backreference count 4, distance 700
    .byte $92, $BB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
