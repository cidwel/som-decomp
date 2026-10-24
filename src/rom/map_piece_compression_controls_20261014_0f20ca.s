.setcpu "65816"
.segment "CODE"
.org $20CA
map_control_0f20ca:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
