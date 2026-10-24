.setcpu "65816"
.segment "CODE"
.org $ADC4
map_control_0fadc4:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $C5 ; same-value copy count/distance
