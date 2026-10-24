.setcpu "65816"
.segment "CODE"
.org $E98C
map_control_0ee98c:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
