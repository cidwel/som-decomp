; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $097A
boss_lz_controls_db097a:
    ; backreference count 3, distance 535
    .byte $82, $16
    ; backreference count 5, distance 2555
    .byte $A9, $FA
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
