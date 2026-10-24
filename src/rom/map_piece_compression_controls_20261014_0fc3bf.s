.setcpu "65816"
.segment "CODE"
.org $C3BF
map_control_0fc3bf:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
