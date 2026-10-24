.setcpu "65816"
.segment "CODE"
.org $0049
map_control_0e0049:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
