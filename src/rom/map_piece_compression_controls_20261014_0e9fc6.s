.setcpu "65816"
.segment "CODE"
.org $9FC6
map_control_0e9fc6:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
