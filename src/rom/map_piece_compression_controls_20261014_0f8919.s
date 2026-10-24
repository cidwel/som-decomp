.setcpu "65816"
.segment "CODE"
.org $8919
map_control_0f8919:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
