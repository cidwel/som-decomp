.setcpu "65816"
.segment "CODE"
.org $0D82
map_control_0f0d82:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
