.setcpu "65816"
.segment "CODE"
.org $1BA5
map_control_0e1ba5:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
