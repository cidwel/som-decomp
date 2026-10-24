.setcpu "65816"
.segment "CODE"
.org $86BB
map_control_0e86bb:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
