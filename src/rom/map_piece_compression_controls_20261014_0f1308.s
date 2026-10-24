.setcpu "65816"
.segment "CODE"
.org $1308
map_control_0f1308:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
