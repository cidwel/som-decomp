.setcpu "65816"
.segment "CODE"
.org $E7A5
map_control_0ee7a5:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
