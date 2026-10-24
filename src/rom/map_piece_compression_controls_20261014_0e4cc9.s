.setcpu "65816"
.segment "CODE"
.org $4CC9
map_control_0e4cc9:
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
