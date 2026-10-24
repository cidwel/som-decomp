.setcpu "65816"
.segment "CODE"
.org $DD58
map_control_0fdd58:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
