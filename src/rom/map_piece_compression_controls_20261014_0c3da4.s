.setcpu "65816"
.segment "CODE"
.org $3DA4
map_control_0c3da4:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
