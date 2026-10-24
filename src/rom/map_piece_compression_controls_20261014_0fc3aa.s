.setcpu "65816"
.segment "CODE"
.org $C3AA
map_control_0fc3aa:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
