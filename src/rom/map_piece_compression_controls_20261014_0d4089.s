.setcpu "65816"
.segment "CODE"
.org $4089
map_control_0d4089:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
