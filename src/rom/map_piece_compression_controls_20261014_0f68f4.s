.setcpu "65816"
.segment "CODE"
.org $68F4
map_control_0f68f4:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
