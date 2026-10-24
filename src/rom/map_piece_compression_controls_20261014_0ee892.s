.setcpu "65816"
.segment "CODE"
.org $E892
map_control_0ee892:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
