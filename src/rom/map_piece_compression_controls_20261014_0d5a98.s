.setcpu "65816"
.segment "CODE"
.org $5A98
map_control_0d5a98:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
