; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D809
boss_lz_controls_dbd809:
    ; backreference count 3, distance 233
    .byte $80, $E8
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
