.setcpu "65816"
.segment "CODE"
.org $AABC
map_control_0faabc:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
