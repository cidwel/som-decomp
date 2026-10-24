.setcpu "65816"
.segment "CODE"
.org $E091
map_control_0ee091:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
