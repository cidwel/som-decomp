.setcpu "65816"
.segment "CODE"
.org $EB32
map_control_0deb32:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
