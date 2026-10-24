.setcpu "65816"
.segment "CODE"
.org $1AEC
map_control_0f1aec:
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
