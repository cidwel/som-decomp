.setcpu "65816"
.segment "CODE"
.org $1C85
map_control_0f1c85:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
