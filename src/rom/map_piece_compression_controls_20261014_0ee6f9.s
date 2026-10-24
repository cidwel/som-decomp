.setcpu "65816"
.segment "CODE"
.org $E6F9
map_control_0ee6f9:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
