.setcpu "65816"
.segment "CODE"
.org $2FBD
map_control_0f2fbd:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
