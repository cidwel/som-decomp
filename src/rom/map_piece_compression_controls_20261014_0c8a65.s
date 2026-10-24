.setcpu "65816"
.segment "CODE"
.org $8A65
map_control_0c8a65:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
