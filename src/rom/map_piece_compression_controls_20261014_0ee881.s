.setcpu "65816"
.segment "CODE"
.org $E881
map_control_0ee881:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
