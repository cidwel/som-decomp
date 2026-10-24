.setcpu "65816"
.segment "CODE"
.org $6482
map_control_0f6482:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C6 ; same-value copy count/distance
