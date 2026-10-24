.setcpu "65816"
.segment "CODE"
.org $FF97
map_control_0dff97:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
