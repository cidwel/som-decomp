.setcpu "65816"
.segment "CODE"
.org $5F58
map_control_0c5f58:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
