.setcpu "65816"
.segment "CODE"
.org $C2C7
map_control_0fc2c7:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6E ; row-distance/count
