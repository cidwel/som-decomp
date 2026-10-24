.setcpu "65816"
.segment "CODE"
.org $0EE2
map_control_0e0ee2:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
