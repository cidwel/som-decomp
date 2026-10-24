.setcpu "65816"
.segment "CODE"
.org $E954
map_control_0ee954:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
