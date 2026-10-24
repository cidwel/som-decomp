.setcpu "65816"
.segment "CODE"
.org $E075
map_control_0ee075:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
