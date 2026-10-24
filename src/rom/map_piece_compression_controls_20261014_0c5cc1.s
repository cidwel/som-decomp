.setcpu "65816"
.segment "CODE"
.org $5CC1
map_control_0c5cc1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
