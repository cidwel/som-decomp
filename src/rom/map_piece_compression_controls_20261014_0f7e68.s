.setcpu "65816"
.segment "CODE"
.org $7E68
map_control_0f7e68:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
