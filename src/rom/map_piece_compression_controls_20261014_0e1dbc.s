.setcpu "65816"
.segment "CODE"
.org $1DBC
map_control_0e1dbc:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E3 ; previous-row copy count
