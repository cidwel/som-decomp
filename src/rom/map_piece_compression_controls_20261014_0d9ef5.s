.setcpu "65816"
.segment "CODE"
.org $9EF5
map_control_0d9ef5:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
