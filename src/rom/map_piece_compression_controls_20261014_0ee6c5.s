.setcpu "65816"
.segment "CODE"
.org $E6C5
map_control_0ee6c5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
