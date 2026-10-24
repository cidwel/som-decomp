.setcpu "65816"
.segment "CODE"
.org $4F57
map_control_0d4f57:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
