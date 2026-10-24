.setcpu "65816"
.segment "CODE"
.org $938E
map_control_0f938e:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
