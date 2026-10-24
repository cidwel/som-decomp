.setcpu "65816"
.segment "CODE"
.org $E77B
map_control_0ee77b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
