.setcpu "65816"
.segment "CODE"
.org $2A98
map_control_0d2a98:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
