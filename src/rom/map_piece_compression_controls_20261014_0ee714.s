.setcpu "65816"
.segment "CODE"
.org $E714
map_control_0ee714:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
