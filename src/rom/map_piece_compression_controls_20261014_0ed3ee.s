.setcpu "65816"
.segment "CODE"
.org $D3EE
map_control_0ed3ee:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
