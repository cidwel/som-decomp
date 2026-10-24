.setcpu "65816"
.segment "CODE"
.org $63EE
map_control_0d63ee:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
