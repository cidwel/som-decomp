.setcpu "65816"
.segment "CODE"
.org $63B4
map_control_0d63b4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
