; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D37D
boss_lz_controls_dbd37d:
    ; backreference count 3, distance 108
    .byte $80, $6B
    ; backreference count 7, distance 110
    .byte $90, $6D
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
