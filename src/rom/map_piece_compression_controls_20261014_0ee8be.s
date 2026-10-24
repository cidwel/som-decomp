.setcpu "65816"
.segment "CODE"
.org $E8BE
map_control_0ee8be:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
