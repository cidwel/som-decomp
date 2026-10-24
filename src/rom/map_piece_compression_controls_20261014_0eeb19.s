.setcpu "65816"
.segment "CODE"
.org $EB19
map_control_0eeb19:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
