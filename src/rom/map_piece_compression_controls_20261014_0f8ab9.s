.setcpu "65816"
.segment "CODE"
.org $8AB9
map_control_0f8ab9:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
