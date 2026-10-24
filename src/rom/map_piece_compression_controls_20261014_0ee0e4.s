.setcpu "65816"
.segment "CODE"
.org $E0E4
map_control_0ee0e4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
