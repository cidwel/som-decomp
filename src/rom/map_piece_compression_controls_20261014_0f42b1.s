.setcpu "65816"
.segment "CODE"
.org $42B1
map_control_0f42b1:
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
