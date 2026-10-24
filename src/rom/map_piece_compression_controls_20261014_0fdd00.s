.setcpu "65816"
.segment "CODE"
.org $DD00
map_control_0fdd00:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
