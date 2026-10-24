.setcpu "65816"
.segment "CODE"
.org $8CD3
map_control_0f8cd3:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
