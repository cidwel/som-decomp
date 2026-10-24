.setcpu "65816"
.segment "CODE"
.org $5B66
map_control_0d5b66:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $52 ; distance low bit/count
