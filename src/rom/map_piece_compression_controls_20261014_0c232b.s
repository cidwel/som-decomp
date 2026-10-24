.setcpu "65816"
.segment "CODE"
.org $232B
map_control_0c232b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
