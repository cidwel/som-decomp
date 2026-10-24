.setcpu "65816"
.segment "CODE"
.org $BB18
map_control_0fbb18:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
