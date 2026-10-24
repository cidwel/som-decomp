.setcpu "65816"
.segment "CODE"
.org $E1B8
map_control_0ee1b8:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
