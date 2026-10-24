.setcpu "65816"
.segment "CODE"
.org $196B
map_control_0c196b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
