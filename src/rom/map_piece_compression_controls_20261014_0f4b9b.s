.setcpu "65816"
.segment "CODE"
.org $4B9B
map_control_0f4b9b:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
