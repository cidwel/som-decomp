.setcpu "65816"
.segment "CODE"
.org $CE80
map_control_0dce80:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
