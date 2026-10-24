.setcpu "65816"
.segment "CODE"
.org $DDA1
map_control_0edda1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
