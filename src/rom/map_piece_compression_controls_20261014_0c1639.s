.setcpu "65816"
.segment "CODE"
.org $1639
map_control_0c1639:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
