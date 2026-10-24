.setcpu "65816"
.segment "CODE"
.org $4318
map_control_0f4318:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
