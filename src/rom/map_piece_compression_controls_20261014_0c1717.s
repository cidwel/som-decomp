.setcpu "65816"
.segment "CODE"
.org $1717
map_control_0c1717:
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
