; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02DC
boss_lz_controls_db02dc:
    ; backreference count 4, distance 151
    .byte $90, $96
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
