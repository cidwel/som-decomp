.setcpu "65816"
.segment "CODE"
.org $883A
map_control_0f883a:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
