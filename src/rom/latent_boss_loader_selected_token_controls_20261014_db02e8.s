; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02E8
boss_lz_controls_db02e8:
    ; backreference count 3, distance 564
    .byte $82, $33
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
