.setcpu "65816"
.segment "CODE"
.org $E74B
map_control_0ee74b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
