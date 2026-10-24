.setcpu "65816"
.segment "CODE"
.org $1B2B
map_control_0f1b2b:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
