.setcpu "65816"
.segment "CODE"
.org $BDA0
map_control_0ebda0:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
