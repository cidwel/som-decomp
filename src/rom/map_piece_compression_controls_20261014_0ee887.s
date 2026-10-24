.setcpu "65816"
.segment "CODE"
.org $E887
map_control_0ee887:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
