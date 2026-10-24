.setcpu "65816"
.segment "CODE"
.org $78C7
map_control_0c78c7:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
