.setcpu "65816"
.segment "CODE"
.org $CD07
map_control_0ecd07:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E4 ; previous-row copy count
