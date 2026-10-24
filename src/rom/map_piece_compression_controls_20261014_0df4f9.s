.setcpu "65816"
.segment "CODE"
.org $F4F9
map_control_0df4f9:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
