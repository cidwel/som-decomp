.setcpu "65816"
.segment "CODE"
.org $03A7
map_control_0f03a7:
    .byte $ED ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
