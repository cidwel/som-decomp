.setcpu "65816"
.segment "CODE"
.org $E877
map_control_0fe877:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
