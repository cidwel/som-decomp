.setcpu "65816"
.segment "CODE"
.org $A978
map_control_0ea978:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
