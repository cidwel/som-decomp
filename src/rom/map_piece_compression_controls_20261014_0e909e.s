.setcpu "65816"
.segment "CODE"
.org $909E
map_control_0e909e:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
