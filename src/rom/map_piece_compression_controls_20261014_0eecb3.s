.setcpu "65816"
.segment "CODE"
.org $ECB3
map_control_0eecb3:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
