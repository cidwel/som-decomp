.setcpu "65816"
.segment "CODE"
.org $3E5D
map_control_0f3e5d:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
