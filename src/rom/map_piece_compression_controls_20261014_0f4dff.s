.setcpu "65816"
.segment "CODE"
.org $4DFF
map_control_0f4dff:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
