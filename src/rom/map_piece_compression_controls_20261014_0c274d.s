.setcpu "65816"
.segment "CODE"
.org $274D
map_control_0c274d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
