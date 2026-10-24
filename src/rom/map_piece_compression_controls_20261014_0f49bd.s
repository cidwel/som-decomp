.setcpu "65816"
.segment "CODE"
.org $49BD
map_control_0f49bd:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
