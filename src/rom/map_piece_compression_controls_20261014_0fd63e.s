.setcpu "65816"
.segment "CODE"
.org $D63E
map_control_0fd63e:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
