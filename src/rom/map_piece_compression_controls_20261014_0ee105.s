.setcpu "65816"
.segment "CODE"
.org $E105
map_control_0ee105:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
