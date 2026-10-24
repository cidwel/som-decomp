.setcpu "65816"
.segment "CODE"
.org $2B80
map_control_0c2b80:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
