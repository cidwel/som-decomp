.setcpu "65816"
.segment "CODE"
.org $90DC
map_control_0c90dc:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
