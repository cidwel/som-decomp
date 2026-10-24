.setcpu "65816"
.segment "CODE"
.org $1241
map_control_0e1241:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
