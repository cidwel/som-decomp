.setcpu "65816"
.segment "CODE"
.org $D6E1
map_control_0ed6e1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
