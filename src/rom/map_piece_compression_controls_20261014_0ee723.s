.setcpu "65816"
.segment "CODE"
.org $E723
map_control_0ee723:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
