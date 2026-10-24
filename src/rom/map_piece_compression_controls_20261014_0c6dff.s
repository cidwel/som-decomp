.setcpu "65816"
.segment "CODE"
.org $6DFF
map_control_0c6dff:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
