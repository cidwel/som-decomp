.setcpu "65816"
.segment "CODE"
.org $486B
map_control_0f486b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
