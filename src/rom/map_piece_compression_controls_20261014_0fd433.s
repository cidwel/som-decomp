.setcpu "65816"
.segment "CODE"
.org $D433
map_control_0fd433:
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7D ; distance low bit/count
