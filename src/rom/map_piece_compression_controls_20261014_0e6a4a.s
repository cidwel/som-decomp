.setcpu "65816"
.segment "CODE"
.org $6A4A
map_control_0e6a4a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
