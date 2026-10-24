; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEF0
boss_lz_controls_dbcef0:
    ; backreference count 3, distance 214
    .byte $80, $D5
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
