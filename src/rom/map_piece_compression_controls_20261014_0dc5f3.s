.setcpu "65816"
.segment "CODE"
.org $C5F3
map_control_0dc5f3:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
