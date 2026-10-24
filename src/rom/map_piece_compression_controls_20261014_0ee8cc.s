.setcpu "65816"
.segment "CODE"
.org $E8CC
map_control_0ee8cc:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
