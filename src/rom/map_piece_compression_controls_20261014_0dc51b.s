.setcpu "65816"
.segment "CODE"
.org $C51B
map_control_0dc51b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
