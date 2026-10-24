.setcpu "65816"
.segment "CODE"
.org $908A
map_control_0f908a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
