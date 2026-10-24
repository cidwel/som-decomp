.setcpu "65816"
.segment "CODE"
.org $13E3
map_control_0c13e3:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
