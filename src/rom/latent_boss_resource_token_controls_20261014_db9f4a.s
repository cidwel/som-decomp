; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F4A
boss_lz_controls_db9f4a:
    ; backreference count 11, distance 133
    .byte $C0, $84
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
