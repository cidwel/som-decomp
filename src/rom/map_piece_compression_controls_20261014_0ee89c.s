.setcpu "65816"
.segment "CODE"
.org $E89C
map_control_0ee89c:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
