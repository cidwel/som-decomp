.setcpu "65816"
.segment "CODE"
.org $8883
map_control_0c8883:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
