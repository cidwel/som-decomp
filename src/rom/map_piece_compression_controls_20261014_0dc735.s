.setcpu "65816"
.segment "CODE"
.org $C735
map_control_0dc735:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
