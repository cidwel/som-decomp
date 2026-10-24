; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04FC
boss_lz_controls_db04fc:
    ; backreference count 4, distance 1368
    .byte $95, $57
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
