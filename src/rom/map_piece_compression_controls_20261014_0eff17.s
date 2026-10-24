.setcpu "65816"
.segment "CODE"
.org $FF17
map_control_0eff17:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
