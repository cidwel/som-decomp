.setcpu "65816"
.segment "CODE"
.org $9F1F
map_control_0d9f1f:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
