.setcpu "65816"
.segment "CODE"
.org $0EE6
map_control_0e0ee6:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
