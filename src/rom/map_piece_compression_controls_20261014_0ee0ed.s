.setcpu "65816"
.segment "CODE"
.org $E0ED
map_control_0ee0ed:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
