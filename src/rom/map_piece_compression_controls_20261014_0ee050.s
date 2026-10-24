.setcpu "65816"
.segment "CODE"
.org $E050
map_control_0ee050:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
