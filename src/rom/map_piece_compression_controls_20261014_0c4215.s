.setcpu "65816"
.segment "CODE"
.org $4215
map_control_0c4215:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
