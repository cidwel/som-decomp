.setcpu "65816"
.segment "CODE"
.org $857B
map_control_0f857b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
