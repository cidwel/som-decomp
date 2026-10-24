.setcpu "65816"
.segment "CODE"
.org $EB3B
map_control_0deb3b:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
