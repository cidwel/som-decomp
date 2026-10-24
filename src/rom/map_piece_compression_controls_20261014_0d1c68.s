.setcpu "65816"
.segment "CODE"
.org $1C68
map_control_0d1c68:
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
