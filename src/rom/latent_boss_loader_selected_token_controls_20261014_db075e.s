; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $075E
boss_lz_controls_db075e:
    ; backreference count 9, distance 1415
    .byte $E5, $86
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
