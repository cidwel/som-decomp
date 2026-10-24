.setcpu "65816"
.segment "CODE"
.org $BEEC
map_control_0dbeec:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
