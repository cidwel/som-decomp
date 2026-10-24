.setcpu "65816"
.segment "CODE"
.org $119D
map_control_0c119d:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
