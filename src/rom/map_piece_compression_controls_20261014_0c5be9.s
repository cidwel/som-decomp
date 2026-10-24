.setcpu "65816"
.segment "CODE"
.org $5BE9
map_control_0c5be9:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
