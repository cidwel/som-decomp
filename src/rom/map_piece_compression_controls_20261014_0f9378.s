.setcpu "65816"
.segment "CODE"
.org $9378
map_control_0f9378:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
