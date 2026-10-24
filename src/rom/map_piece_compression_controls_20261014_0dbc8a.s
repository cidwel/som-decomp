.setcpu "65816"
.segment "CODE"
.org $BC8A
map_control_0dbc8a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
