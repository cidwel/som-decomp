.setcpu "65816"
.segment "CODE"
.org $FCF1
map_control_0ffcf1:
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $58 ; row-distance/count
