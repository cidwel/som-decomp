.setcpu "65816"
.segment "CODE"
.org $71C8
map_control_0c71c8:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
