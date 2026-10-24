.setcpu "65816"
.segment "CODE"
.org $8E53
map_control_0f8e53:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
