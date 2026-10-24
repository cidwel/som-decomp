.setcpu "65816"
.segment "CODE"
.org $714B
map_control_0d714b:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
