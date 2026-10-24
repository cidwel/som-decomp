.setcpu "65816"
.segment "CODE"
.org $3BE4
map_control_0f3be4:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
