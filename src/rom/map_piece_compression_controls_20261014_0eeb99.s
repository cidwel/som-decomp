.setcpu "65816"
.segment "CODE"
.org $EB99
map_control_0eeb99:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
