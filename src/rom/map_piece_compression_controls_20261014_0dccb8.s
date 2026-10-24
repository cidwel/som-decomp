.setcpu "65816"
.segment "CODE"
.org $CCB8
map_control_0dccb8:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
