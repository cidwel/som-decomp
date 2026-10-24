.setcpu "65816"
.segment "CODE"
.org $E03A
map_control_0ee03a:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
