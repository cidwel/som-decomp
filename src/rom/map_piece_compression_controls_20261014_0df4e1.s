.setcpu "65816"
.segment "CODE"
.org $F4E1
map_control_0df4e1:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
