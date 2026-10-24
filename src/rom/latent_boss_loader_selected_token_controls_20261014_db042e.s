; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $042E
boss_lz_controls_db042e:
    ; backreference count 4, distance 27
    .byte $90, $1A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
