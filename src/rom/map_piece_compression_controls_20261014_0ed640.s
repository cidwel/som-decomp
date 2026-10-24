.setcpu "65816"
.segment "CODE"
.org $D640
map_control_0ed640:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C5 ; same-value copy count/distance
