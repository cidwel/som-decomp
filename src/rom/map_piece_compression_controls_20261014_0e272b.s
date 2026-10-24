.setcpu "65816"
.segment "CODE"
.org $272B
map_control_0e272b:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
