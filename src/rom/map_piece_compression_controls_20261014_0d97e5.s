.setcpu "65816"
.segment "CODE"
.org $97E5
map_control_0d97e5:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
