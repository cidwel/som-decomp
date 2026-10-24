; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $008A
boss_lz_controls_db008a:
    ; backreference count 4, distance 39
    .byte $90, $26
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
