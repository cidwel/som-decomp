.setcpu "65816"
.segment "CODE"
.org $00E9
map_control_0f00e9:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
