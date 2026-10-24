.setcpu "65816"
.segment "CODE"
.org $C808
map_control_0dc808:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
