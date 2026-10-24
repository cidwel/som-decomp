.setcpu "65816"
.segment "CODE"
.org $2AD2
map_control_0e2ad2:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
