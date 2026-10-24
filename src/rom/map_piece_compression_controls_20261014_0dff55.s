.setcpu "65816"
.segment "CODE"
.org $FF55
map_control_0dff55:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
