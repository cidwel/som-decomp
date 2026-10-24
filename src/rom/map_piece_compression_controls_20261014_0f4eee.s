.setcpu "65816"
.segment "CODE"
.org $4EEE
map_control_0f4eee:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
