.setcpu "65816"
.segment "CODE"
.org $0619
map_control_0f0619:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
