.setcpu "65816"
.segment "CODE"
.org $7634
map_control_0d7634:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
