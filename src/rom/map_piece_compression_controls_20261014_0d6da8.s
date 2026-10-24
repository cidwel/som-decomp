.setcpu "65816"
.segment "CODE"
.org $6DA8
map_control_0d6da8:
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
