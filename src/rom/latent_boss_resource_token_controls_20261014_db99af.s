; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $99AF
boss_lz_controls_db99af:
    ; backreference count 3, distance 76
    .byte $80, $4B
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
