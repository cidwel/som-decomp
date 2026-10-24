.setcpu "65816"
.segment "CODE"
.org $9C8B
map_control_0f9c8b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
