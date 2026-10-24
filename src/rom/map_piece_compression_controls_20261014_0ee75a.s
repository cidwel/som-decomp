.setcpu "65816"
.segment "CODE"
.org $E75A
map_control_0ee75a:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
