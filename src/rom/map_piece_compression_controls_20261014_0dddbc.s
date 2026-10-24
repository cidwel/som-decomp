.setcpu "65816"
.segment "CODE"
.org $DDBC
map_control_0dddbc:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
