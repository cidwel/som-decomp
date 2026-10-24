.setcpu "65816"
.segment "CODE"
.org $BCE9
map_control_0fbce9:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
