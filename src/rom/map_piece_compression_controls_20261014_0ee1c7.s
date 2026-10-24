.setcpu "65816"
.segment "CODE"
.org $E1C7
map_control_0ee1c7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
