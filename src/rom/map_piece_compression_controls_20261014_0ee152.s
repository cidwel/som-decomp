.setcpu "65816"
.segment "CODE"
.org $E152
map_control_0ee152:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
