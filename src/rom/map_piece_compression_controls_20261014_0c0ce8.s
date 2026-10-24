.setcpu "65816"
.segment "CODE"
.org $0CE8
map_control_0c0ce8:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
