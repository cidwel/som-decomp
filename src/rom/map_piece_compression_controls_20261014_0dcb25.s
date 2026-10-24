.setcpu "65816"
.segment "CODE"
.org $CB25
map_control_0dcb25:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
