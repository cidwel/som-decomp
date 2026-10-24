; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC01
boss_lz_controls_dbbc01:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 38; subsequent asset bytes excluded
    .byte $25
