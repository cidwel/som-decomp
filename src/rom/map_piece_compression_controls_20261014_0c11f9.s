.setcpu "65816"
.segment "CODE"
.org $11F9
map_control_0c11f9:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
