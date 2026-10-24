.setcpu "65816"
.segment "CODE"
.org $705D
map_control_0e705d:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
