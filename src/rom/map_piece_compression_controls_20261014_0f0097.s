.setcpu "65816"
.segment "CODE"
.org $0097
map_control_0f0097:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
