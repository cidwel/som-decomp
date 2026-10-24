.setcpu "65816"
.segment "CODE"
.org $E6FC
map_control_0fe6fc:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
