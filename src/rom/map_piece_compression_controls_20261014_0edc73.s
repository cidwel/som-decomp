.setcpu "65816"
.segment "CODE"
.org $DC73
map_control_0edc73:
    .byte $EE ; backreference distance high bits
    .byte $90 ; distance low bit/count
