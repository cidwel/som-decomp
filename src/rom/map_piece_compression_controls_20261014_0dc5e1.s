.setcpu "65816"
.segment "CODE"
.org $C5E1
map_control_0dc5e1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
