.setcpu "65816"
.segment "CODE"
.org $9DE0
map_control_0f9de0:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
