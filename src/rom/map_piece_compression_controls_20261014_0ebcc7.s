.setcpu "65816"
.segment "CODE"
.org $BCC7
map_control_0ebcc7:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
