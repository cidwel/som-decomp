.setcpu "65816"
.segment "CODE"
.org $E806
map_control_0ee806:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
