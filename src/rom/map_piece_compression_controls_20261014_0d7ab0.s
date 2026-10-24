.setcpu "65816"
.segment "CODE"
.org $7AB0
map_control_0d7ab0:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
