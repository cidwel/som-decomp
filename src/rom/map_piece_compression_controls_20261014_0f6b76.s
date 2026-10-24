.setcpu "65816"
.segment "CODE"
.org $6B76
map_control_0f6b76:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
