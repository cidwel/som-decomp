.setcpu "65816"
.segment "CODE"
.org $5D26
map_control_0f5d26:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
