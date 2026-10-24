.setcpu "65816"
.segment "CODE"
.org $3390
map_control_0f3390:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E3 ; previous-row copy count
