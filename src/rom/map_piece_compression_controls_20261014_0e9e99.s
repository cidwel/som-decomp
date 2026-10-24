.setcpu "65816"
.segment "CODE"
.org $9E99
map_control_0e9e99:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
