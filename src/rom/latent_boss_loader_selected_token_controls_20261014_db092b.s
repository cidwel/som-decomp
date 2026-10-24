; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $092B
boss_lz_controls_db092b:
    ; backreference count 4, distance 1802
    .byte $97, $09
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
