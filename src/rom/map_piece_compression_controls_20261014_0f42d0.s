.setcpu "65816"
.segment "CODE"
.org $42D0
map_control_0f42d0:
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
