.setcpu "65816"
.segment "CODE"
.org $BC10
map_control_0dbc10:
    .byte $E0 ; previous-row copy escape
    .byte $BC ; row-distance/count
