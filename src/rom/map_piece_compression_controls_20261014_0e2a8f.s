.setcpu "65816"
.segment "CODE"
.org $2A8F
map_control_0e2a8f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C5 ; same-value copy count/distance
