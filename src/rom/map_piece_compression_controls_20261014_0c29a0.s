.setcpu "65816"
.segment "CODE"
.org $29A0
map_control_0c29a0:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
