.setcpu "65816"
.segment "CODE"
.org $72C7
map_control_0e72c7:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
