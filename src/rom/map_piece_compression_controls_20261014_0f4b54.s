.setcpu "65816"
.segment "CODE"
.org $4B54
map_control_0f4b54:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
