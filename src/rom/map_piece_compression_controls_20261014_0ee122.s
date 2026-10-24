.setcpu "65816"
.segment "CODE"
.org $E122
map_control_0ee122:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
