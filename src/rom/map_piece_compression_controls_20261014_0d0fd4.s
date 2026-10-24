.setcpu "65816"
.segment "CODE"
.org $0FD4
map_control_0d0fd4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
