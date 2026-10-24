.setcpu "65816"
.segment "CODE"
.org $E0A8
map_control_0fe0a8:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
