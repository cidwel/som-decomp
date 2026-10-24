.setcpu "65816"
.segment "CODE"
.org $9131
map_control_0c9131:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
