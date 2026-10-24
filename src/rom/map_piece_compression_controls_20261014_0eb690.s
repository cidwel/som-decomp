.setcpu "65816"
.segment "CODE"
.org $B690
map_control_0eb690:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
