.setcpu "65816"
.segment "CODE"
.org $98C2
map_control_0d98c2:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
