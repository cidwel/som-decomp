.setcpu "65816"
.segment "CODE"
.org $1CE0
map_control_0f1ce0:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
