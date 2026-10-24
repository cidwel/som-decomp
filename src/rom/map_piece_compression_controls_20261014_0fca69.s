.setcpu "65816"
.segment "CODE"
.org $CA69
map_control_0fca69:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
