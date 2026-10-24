.setcpu "65816"
.segment "CODE"
.org $2F70
map_control_0c2f70:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
