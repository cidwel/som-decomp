.setcpu "65816"
.segment "CODE"
.org $AF28
map_control_0faf28:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
