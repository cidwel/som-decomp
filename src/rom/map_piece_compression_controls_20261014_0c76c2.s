.setcpu "65816"
.segment "CODE"
.org $76C2
map_control_0c76c2:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
