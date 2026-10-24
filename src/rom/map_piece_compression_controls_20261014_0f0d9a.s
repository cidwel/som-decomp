.setcpu "65816"
.segment "CODE"
.org $0D9A
map_control_0f0d9a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
