; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCE1
boss_lz_controls_dabce1:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
