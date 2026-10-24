.setcpu "65816"
.segment "CODE"
.org $39F6
map_control_0f39f6:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
