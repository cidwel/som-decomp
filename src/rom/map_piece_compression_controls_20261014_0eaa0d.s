.setcpu "65816"
.segment "CODE"
.org $AA0D
map_control_0eaa0d:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
