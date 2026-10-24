.setcpu "65816"
.segment "CODE"
.org $E372
map_control_0ee372:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
