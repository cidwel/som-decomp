.setcpu "65816"
.segment "CODE"
.org $E1F7
map_control_0ee1f7:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
