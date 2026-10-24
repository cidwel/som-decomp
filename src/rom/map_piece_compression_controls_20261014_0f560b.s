.setcpu "65816"
.segment "CODE"
.org $560B
map_control_0f560b:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
