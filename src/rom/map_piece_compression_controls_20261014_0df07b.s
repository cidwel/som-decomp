.setcpu "65816"
.segment "CODE"
.org $F07B
map_control_0df07b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
