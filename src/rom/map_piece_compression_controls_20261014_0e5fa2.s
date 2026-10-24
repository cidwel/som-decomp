.setcpu "65816"
.segment "CODE"
.org $5FA2
map_control_0e5fa2:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
