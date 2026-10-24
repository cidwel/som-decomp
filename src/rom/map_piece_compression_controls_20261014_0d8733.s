.setcpu "65816"
.segment "CODE"
.org $8733
map_control_0d8733:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
