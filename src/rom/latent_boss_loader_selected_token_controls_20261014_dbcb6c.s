; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB6C
boss_lz_controls_dbcb6c:
    ; backreference count 3, distance 223
    .byte $80, $DE
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
