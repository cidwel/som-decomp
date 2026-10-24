.setcpu "65816"
.segment "CODE"
.org $F443
map_control_0ef443:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
