.setcpu "65816"
.segment "CODE"
.org $4E3B
map_control_0d4e3b:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
