.setcpu "65816"
.segment "CODE"
.org $ADB4
map_control_0fadb4:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
