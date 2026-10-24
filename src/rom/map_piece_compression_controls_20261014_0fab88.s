.setcpu "65816"
.segment "CODE"
.org $AB88
map_control_0fab88:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
