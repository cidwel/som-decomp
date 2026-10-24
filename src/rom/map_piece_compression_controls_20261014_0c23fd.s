.setcpu "65816"
.segment "CODE"
.org $23FD
map_control_0c23fd:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
