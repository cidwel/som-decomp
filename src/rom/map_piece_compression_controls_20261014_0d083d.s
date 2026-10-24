.setcpu "65816"
.segment "CODE"
.org $083D
map_control_0d083d:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
