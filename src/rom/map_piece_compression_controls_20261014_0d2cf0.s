.setcpu "65816"
.segment "CODE"
.org $2CF0
map_control_0d2cf0:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
