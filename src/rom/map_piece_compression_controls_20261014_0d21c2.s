.setcpu "65816"
.segment "CODE"
.org $21C2
map_control_0d21c2:
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
