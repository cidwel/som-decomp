.setcpu "65816"
.segment "CODE"
.org $13AB
map_control_0c13ab:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
