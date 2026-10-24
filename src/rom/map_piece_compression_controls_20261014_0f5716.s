.setcpu "65816"
.segment "CODE"
.org $5716
map_control_0f5716:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
