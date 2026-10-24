.setcpu "65816"
.segment "CODE"
.org $2687
map_control_0e2687:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
