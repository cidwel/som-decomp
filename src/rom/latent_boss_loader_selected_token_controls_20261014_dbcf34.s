; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF34
boss_lz_controls_dbcf34:
    ; backreference count 4, distance 1024
    .byte $93, $FF
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
