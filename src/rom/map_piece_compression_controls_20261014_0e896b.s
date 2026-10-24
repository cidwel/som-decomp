.setcpu "65816"
.segment "CODE"
.org $896B
map_control_0e896b:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
