.setcpu "65816"
.segment "CODE"
.org $5EE4
map_control_0d5ee4:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
