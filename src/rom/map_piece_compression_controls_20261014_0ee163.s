.setcpu "65816"
.segment "CODE"
.org $E163
map_control_0ee163:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
