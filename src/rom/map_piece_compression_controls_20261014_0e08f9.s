.setcpu "65816"
.segment "CODE"
.org $08F9
map_control_0e08f9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
