.setcpu "65816"
.segment "CODE"
.org $3822
map_control_0f3822:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C3 ; same-value copy count/distance
