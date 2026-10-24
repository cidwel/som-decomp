.setcpu "65816"
.segment "CODE"
.org $EB35
map_control_0eeb35:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
