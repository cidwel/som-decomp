.setcpu "65816"
.segment "CODE"
.org $E6FE
map_control_0ee6fe:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
