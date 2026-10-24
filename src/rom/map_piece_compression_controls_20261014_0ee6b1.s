.setcpu "65816"
.segment "CODE"
.org $E6B1
map_control_0ee6b1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
