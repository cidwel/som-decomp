.setcpu "65816"
.segment "CODE"
.org $5B34
map_control_0d5b34:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
