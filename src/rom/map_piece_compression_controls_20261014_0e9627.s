.setcpu "65816"
.segment "CODE"
.org $9627
map_control_0e9627:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
