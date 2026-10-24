.setcpu "65816"
.segment "CODE"
.org $6B88
map_control_0f6b88:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
