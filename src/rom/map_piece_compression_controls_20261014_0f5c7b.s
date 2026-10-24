.setcpu "65816"
.segment "CODE"
.org $5C7B
map_control_0f5c7b:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
