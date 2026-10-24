.setcpu "65816"
.segment "CODE"
.org $E1DC
map_control_0ee1dc:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
