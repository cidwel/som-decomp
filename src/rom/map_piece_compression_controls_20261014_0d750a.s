.setcpu "65816"
.segment "CODE"
.org $750A
map_control_0d750a:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
