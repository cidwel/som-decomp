.setcpu "65816"
.segment "CODE"
.org $8745
map_control_0c8745:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
