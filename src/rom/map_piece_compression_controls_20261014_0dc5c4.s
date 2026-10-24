.setcpu "65816"
.segment "CODE"
.org $C5C4
map_control_0dc5c4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
