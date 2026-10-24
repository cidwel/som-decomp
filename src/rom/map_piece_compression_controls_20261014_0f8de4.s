.setcpu "65816"
.segment "CODE"
.org $8DE4
map_control_0f8de4:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
