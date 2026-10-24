; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04EA
boss_lz_controls_db04ea:
    ; backreference count 6, distance 1608
    .byte $B6, $47
    ; backreference count 3, distance 1061
    .byte $84, $24
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
