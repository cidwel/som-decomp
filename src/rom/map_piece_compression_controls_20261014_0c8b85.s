.setcpu "65816"
.segment "CODE"
.org $8B85
map_control_0c8b85:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
