.setcpu "65816"
.segment "CODE"
.org $4146
map_control_0c4146:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
