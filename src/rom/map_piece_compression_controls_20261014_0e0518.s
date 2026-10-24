.setcpu "65816"
.segment "CODE"
.org $0518
map_control_0e0518:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
