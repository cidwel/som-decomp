.setcpu "65816"
.segment "CODE"
.org $EC65
map_control_0eec65:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
