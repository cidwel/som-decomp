; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9ED1
boss_lz_controls_db9ed1:
    ; backreference count 5, distance 6
    .byte $90, $05
    ; backreference count 18, distance 904
    .byte $FB, $87
    ; backreference count 4, distance 72
    .byte $88, $47
    ; literal count 19; subsequent asset bytes excluded
    .byte $12
