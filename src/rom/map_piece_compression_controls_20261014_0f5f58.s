.setcpu "65816"
.segment "CODE"
.org $5F58
map_control_0f5f58:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
