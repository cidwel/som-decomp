; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06CC
boss_lz_controls_db06cc:
    ; backreference count 4, distance 1900
    .byte $97, $6B
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
