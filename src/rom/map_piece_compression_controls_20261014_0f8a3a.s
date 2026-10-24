.setcpu "65816"
.segment "CODE"
.org $8A3A
map_control_0f8a3a:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
