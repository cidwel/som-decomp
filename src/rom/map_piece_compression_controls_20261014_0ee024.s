.setcpu "65816"
.segment "CODE"
.org $E024
map_control_0ee024:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
