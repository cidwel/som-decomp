.setcpu "65816"
.segment "CODE"
.org $0883
map_control_0f0883:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
