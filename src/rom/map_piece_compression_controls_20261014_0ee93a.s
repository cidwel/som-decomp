.setcpu "65816"
.segment "CODE"
.org $E93A
map_control_0ee93a:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
