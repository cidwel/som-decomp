.setcpu "65816"
.segment "CODE"
.org $8E28
map_control_0f8e28:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
