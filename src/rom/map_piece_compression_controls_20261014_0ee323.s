.setcpu "65816"
.segment "CODE"
.org $E323
map_control_0ee323:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
