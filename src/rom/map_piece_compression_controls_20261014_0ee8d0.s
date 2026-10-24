.setcpu "65816"
.segment "CODE"
.org $E8D0
map_control_0ee8d0:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
