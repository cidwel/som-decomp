.setcpu "65816"
.segment "CODE"
.org $49E3
map_control_0f49e3:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
