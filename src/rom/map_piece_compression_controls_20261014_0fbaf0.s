.setcpu "65816"
.segment "CODE"
.org $BAF0
map_control_0fbaf0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
