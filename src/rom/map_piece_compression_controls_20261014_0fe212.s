.setcpu "65816"
.segment "CODE"
.org $E212
map_control_0fe212:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
