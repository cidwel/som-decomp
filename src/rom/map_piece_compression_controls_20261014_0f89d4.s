.setcpu "65816"
.segment "CODE"
.org $89D4
map_control_0f89d4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
