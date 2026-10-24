.setcpu "65816"
.segment "CODE"
.org $6CBD
map_control_0c6cbd:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count
