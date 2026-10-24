.setcpu "65816"
.segment "CODE"
.org $FB4E
map_control_0cfb4e:
    .byte $CD ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
