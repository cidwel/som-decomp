.setcpu "65816"
.segment "CODE"
.org $89F6
map_control_0f89f6:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
