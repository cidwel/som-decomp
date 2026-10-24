.setcpu "65816"
.segment "CODE"
.org $7174
map_control_0c7174:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
