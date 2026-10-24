.setcpu "65816"
.segment "CODE"
.org $71E4
map_control_0c71e4:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
