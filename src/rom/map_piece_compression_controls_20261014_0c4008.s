.setcpu "65816"
.segment "CODE"
.org $4008
map_control_0c4008:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
