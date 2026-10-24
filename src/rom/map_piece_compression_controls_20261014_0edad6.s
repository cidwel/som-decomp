.setcpu "65816"
.segment "CODE"
.org $DAD6
map_control_0edad6:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
