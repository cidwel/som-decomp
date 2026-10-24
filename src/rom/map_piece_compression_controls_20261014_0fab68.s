.setcpu "65816"
.segment "CODE"
.org $AB68
map_control_0fab68:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
