.setcpu "65816"
.segment "CODE"
.org $E7EE
map_control_0ee7ee:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
