.setcpu "65816"
.segment "CODE"
.org $5C20
map_control_0f5c20:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
