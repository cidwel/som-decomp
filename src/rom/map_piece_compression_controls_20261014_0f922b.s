.setcpu "65816"
.segment "CODE"
.org $922B
map_control_0f922b:
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
