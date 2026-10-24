.setcpu "65816"
.segment "CODE"
.org $E0A4
map_control_0ee0a4:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
