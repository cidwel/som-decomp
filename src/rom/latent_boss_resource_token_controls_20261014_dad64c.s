; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D64C
boss_lz_controls_dad64c:
    ; backreference count 3, distance 21
    .byte $80, $14
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
