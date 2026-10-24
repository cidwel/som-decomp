; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE1C
boss_lz_controls_dabe1c:
    ; backreference count 3, distance 369
    .byte $81, $70
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
