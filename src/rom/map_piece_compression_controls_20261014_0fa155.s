.setcpu "65816"
.segment "CODE"
.org $A155
map_control_0fa155:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
