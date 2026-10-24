.setcpu "65816"
.segment "CODE"
.org $E30B
map_control_0ee30b:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
