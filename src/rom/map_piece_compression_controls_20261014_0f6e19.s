.setcpu "65816"
.segment "CODE"
.org $6E19
map_control_0f6e19:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
