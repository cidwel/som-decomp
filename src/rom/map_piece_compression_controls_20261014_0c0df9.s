.setcpu "65816"
.segment "CODE"
.org $0DF9
map_control_0c0df9:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
