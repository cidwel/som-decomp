.setcpu "65816"
.segment "CODE"
.org $983B
map_control_0f983b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
