.setcpu "65816"
.segment "CODE"
.org $57A9
map_control_0f57a9:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
