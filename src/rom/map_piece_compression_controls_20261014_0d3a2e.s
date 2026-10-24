.setcpu "65816"
.segment "CODE"
.org $3A2E
map_control_0d3a2e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
