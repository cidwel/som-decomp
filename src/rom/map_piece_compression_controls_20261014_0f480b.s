.setcpu "65816"
.segment "CODE"
.org $480B
map_control_0f480b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
