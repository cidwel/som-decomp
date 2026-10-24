.setcpu "65816"
.segment "CODE"
.org $1256
map_control_0e1256:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
