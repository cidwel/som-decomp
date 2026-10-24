.setcpu "65816"
.segment "CODE"
.org $F937
map_control_0ff937:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
