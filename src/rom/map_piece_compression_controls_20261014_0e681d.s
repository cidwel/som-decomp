.setcpu "65816"
.segment "CODE"
.org $681D
map_control_0e681d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
