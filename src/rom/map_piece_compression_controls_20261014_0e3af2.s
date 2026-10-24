.setcpu "65816"
.segment "CODE"
.org $3AF2
map_control_0e3af2:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
