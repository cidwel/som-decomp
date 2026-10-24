.setcpu "65816"
.segment "CODE"
.org $DD91
map_control_0fdd91:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
