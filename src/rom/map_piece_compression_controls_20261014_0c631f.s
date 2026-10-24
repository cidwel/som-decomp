.setcpu "65816"
.segment "CODE"
.org $631F
map_control_0c631f:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
