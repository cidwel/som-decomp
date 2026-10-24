.setcpu "65816"
.segment "CODE"
.org $AB03
map_control_0eab03:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
