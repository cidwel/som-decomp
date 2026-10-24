.setcpu "65816"
.segment "CODE"
.org $4664
map_control_0f4664:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
