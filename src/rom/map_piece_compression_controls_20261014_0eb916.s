.setcpu "65816"
.segment "CODE"
.org $B916
map_control_0eb916:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
