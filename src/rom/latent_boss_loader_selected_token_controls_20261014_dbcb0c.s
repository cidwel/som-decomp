; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB0C
boss_lz_controls_dbcb0c:
    ; backreference count 3, distance 230
    .byte $80, $E5
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
