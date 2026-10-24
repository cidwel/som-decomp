.setcpu "65816"
.segment "CODE"
.org $2755
map_control_0c2755:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
