.setcpu "65816"
.segment "CODE"
.org $477D
map_control_0f477d:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
