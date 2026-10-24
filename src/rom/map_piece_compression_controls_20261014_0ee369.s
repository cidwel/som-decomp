.setcpu "65816"
.segment "CODE"
.org $E369
map_control_0ee369:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
