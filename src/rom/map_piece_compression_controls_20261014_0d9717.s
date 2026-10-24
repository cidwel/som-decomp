.setcpu "65816"
.segment "CODE"
.org $9717
map_control_0d9717:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
