.setcpu "65816"
.segment "CODE"
.org $D5E9
map_control_0fd5e9:
    .byte $E5 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
