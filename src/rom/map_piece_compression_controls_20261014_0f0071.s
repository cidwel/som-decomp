.setcpu "65816"
.segment "CODE"
.org $0071
map_control_0f0071:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
