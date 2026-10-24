.setcpu "65816"
.segment "CODE"
.org $AEE4
map_control_0faee4:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
