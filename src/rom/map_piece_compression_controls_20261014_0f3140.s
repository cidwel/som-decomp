.setcpu "65816"
.segment "CODE"
.org $3140
map_control_0f3140:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
