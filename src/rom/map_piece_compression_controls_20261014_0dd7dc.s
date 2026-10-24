.setcpu "65816"
.segment "CODE"
.org $D7DC
map_control_0dd7dc:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
