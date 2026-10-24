.setcpu "65816"
.segment "CODE"
.org $0630
map_control_0f0630:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
