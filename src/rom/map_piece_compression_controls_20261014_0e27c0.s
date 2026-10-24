.setcpu "65816"
.segment "CODE"
.org $27C0
map_control_0e27c0:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
