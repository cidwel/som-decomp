.setcpu "65816"
.segment "CODE"
.org $1B52
map_control_0e1b52:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
