.setcpu "65816"
.segment "CODE"
.org $C6C3
map_control_0dc6c3:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
