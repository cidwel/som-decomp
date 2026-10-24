.setcpu "65816"
.segment "CODE"
.org $E0D6
map_control_0ee0d6:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
