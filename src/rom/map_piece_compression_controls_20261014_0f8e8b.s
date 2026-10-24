.setcpu "65816"
.segment "CODE"
.org $8E8B
map_control_0f8e8b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
