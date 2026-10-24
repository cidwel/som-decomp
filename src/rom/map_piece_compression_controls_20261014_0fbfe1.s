.setcpu "65816"
.segment "CODE"
.org $BFE1
map_control_0fbfe1:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
