.setcpu "65816"
.segment "CODE"
.org $4E21
map_control_0f4e21:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
