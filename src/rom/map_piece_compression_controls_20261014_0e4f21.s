.setcpu "65816"
.segment "CODE"
.org $4F21
map_control_0e4f21:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
