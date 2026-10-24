; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE61
boss_lz_controls_dbbe61:
    ; backreference count 3, distance 31
    .byte $80, $1E
    ; literal count 72; subsequent asset bytes excluded
    .byte $47
