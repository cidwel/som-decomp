.setcpu "65816"
.segment "CODE"
.org $5310
map_control_0f5310:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C7 ; same-value copy count/distance
