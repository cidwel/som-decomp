.setcpu "65816"
.segment "CODE"
.org $2A6E
map_control_0e2a6e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
