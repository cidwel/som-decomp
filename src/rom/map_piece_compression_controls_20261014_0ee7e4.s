.setcpu "65816"
.segment "CODE"
.org $E7E4
map_control_0ee7e4:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
