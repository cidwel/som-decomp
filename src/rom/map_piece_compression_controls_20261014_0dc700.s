.setcpu "65816"
.segment "CODE"
.org $C700
map_control_0dc700:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
