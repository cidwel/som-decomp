; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01B2
boss_lz_controls_db01b2:
    ; backreference count 3, distance 324
    .byte $81, $43
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
