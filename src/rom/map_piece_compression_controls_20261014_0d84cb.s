.setcpu "65816"
.segment "CODE"
.org $84CB
map_control_0d84cb:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C9 ; same-value copy count/distance
