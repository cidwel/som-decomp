.setcpu "65816"
.segment "CODE"
.org $00A5
map_control_0e00a5:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
