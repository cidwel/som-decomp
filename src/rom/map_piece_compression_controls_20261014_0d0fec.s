.setcpu "65816"
.segment "CODE"
.org $0FEC
map_control_0d0fec:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
