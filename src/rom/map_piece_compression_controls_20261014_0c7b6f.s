.setcpu "65816"
.segment "CODE"
.org $7B6F
map_control_0c7b6f:
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
