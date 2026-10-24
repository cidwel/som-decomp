.setcpu "65816"
.segment "CODE"
.org $C790
map_control_0ec790:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
