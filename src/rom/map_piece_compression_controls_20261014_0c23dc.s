.setcpu "65816"
.segment "CODE"
.org $23DC
map_control_0c23dc:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
