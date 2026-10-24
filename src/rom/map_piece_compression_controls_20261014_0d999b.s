.setcpu "65816"
.segment "CODE"
.org $999B
map_control_0d999b:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
