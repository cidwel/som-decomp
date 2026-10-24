.setcpu "65816"
.segment "CODE"
.org $B4D7
map_control_0fb4d7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
