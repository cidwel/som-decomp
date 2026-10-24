.setcpu "65816"
.segment "CODE"
.org $E283
map_control_0ee283:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
