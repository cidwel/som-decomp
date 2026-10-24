.setcpu "65816"
.segment "CODE"
.org $AD2D
map_control_0fad2d:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
