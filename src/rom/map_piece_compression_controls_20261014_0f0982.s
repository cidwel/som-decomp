.setcpu "65816"
.segment "CODE"
.org $0982
map_control_0f0982:
    .byte $DF ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
