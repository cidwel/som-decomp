.setcpu "65816"
.segment "CODE"
.org $57A4
map_control_0c57a4:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
