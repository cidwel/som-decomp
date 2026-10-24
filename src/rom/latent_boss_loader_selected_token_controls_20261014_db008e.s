; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $008E
boss_lz_controls_db008e:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
