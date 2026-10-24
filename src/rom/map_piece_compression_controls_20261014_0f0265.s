.setcpu "65816"
.segment "CODE"
.org $0265
map_control_0f0265:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
