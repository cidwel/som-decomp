.setcpu "65816"
.segment "CODE"
.org $E7F8
map_control_0ee7f8:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
