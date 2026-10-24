.setcpu "65816"
.segment "CODE"
.org $130D
map_control_0c130d:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
