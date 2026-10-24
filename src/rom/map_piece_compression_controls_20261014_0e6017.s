.setcpu "65816"
.segment "CODE"
.org $6017
map_control_0e6017:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
