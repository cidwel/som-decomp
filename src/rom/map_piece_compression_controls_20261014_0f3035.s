.setcpu "65816"
.segment "CODE"
.org $3035
map_control_0f3035:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
