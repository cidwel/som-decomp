.setcpu "65816"
.segment "CODE"
.org $3DCB
map_control_0f3dcb:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
