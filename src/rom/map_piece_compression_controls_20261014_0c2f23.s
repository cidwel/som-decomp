.setcpu "65816"
.segment "CODE"
.org $2F23
map_control_0c2f23:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
