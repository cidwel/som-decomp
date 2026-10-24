.setcpu "65816"
.segment "CODE"
.org $E76B
map_control_0de76b:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
