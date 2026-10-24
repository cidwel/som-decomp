.setcpu "65816"
.segment "CODE"
.org $D998
map_control_0ed998:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
