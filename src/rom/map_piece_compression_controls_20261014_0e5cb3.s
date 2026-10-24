.setcpu "65816"
.segment "CODE"
.org $5CB3
map_control_0e5cb3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
