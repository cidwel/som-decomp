.setcpu "65816"
.segment "CODE"
.org $F4A9
map_control_0df4a9:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
