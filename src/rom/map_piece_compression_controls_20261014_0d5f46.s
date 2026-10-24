.setcpu "65816"
.segment "CODE"
.org $5F46
map_control_0d5f46:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
