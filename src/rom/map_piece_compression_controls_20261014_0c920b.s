.setcpu "65816"
.segment "CODE"
.org $920B
map_control_0c920b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
