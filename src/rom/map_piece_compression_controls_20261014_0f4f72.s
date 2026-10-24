.setcpu "65816"
.segment "CODE"
.org $4F72
map_control_0f4f72:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
