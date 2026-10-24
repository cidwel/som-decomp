.setcpu "65816"
.segment "CODE"
.org $3DE0
map_control_0f3de0:
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
