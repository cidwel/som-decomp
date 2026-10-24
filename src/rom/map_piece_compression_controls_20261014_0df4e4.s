.setcpu "65816"
.segment "CODE"
.org $F4E4
map_control_0df4e4:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
