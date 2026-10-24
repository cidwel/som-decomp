.setcpu "65816"
.segment "CODE"
.org $E174
map_control_0ee174:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
