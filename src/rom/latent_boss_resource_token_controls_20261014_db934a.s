; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $934A
boss_lz_controls_db934a:
    ; backreference count 3, distance 1101
    .byte $84, $4C
    ; literal count 23; subsequent asset bytes excluded
    .byte $16
