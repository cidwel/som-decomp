.setcpu "65816"
.segment "CODE"
.org $4019
map_control_0f4019:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
