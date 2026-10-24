.setcpu "65816"
.segment "CODE"
.org $C4C5
map_control_0fc4c5:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
