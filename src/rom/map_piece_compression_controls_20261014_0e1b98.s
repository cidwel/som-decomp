.setcpu "65816"
.segment "CODE"
.org $1B98
map_control_0e1b98:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
