.setcpu "65816"
.segment "CODE"
.org $2A38
map_control_0e2a38:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
