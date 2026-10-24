; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $083D
boss_lz_controls_db083d:
    ; backreference count 3, distance 1218
    .byte $84, $C1
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
