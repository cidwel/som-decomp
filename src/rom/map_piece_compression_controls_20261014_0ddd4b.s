.setcpu "65816"
.segment "CODE"
.org $DD4B
map_control_0ddd4b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
