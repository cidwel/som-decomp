.setcpu "65816"
.segment "CODE"
.org $0B4B
map_control_0e0b4b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
