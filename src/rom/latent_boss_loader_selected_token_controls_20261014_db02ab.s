; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02AB
boss_lz_controls_db02ab:
    ; backreference count 3, distance 84
    .byte $80, $53
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
