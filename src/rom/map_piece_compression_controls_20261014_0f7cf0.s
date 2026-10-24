.setcpu "65816"
.segment "CODE"
.org $7CF0
map_control_0f7cf0:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
