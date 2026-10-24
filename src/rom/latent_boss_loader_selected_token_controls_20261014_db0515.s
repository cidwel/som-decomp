; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0515
boss_lz_controls_db0515:
    ; backreference count 5, distance 1471
    .byte $A5, $BE
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
