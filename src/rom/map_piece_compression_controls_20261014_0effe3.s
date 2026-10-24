.setcpu "65816"
.segment "CODE"
.org $FFE3
map_control_0effe3:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
