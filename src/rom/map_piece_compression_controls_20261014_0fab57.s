.setcpu "65816"
.segment "CODE"
.org $AB57
map_control_0fab57:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
