.setcpu "65816"
.segment "CODE"
.org $AEC0
map_control_0faec0:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
