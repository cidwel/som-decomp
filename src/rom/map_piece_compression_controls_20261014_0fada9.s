.setcpu "65816"
.segment "CODE"
.org $ADA9
map_control_0fada9:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
