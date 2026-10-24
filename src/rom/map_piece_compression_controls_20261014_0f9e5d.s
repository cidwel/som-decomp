.setcpu "65816"
.segment "CODE"
.org $9E5D
map_control_0f9e5d:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
