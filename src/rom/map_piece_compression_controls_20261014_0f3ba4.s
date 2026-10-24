.setcpu "65816"
.segment "CODE"
.org $3BA4
map_control_0f3ba4:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
