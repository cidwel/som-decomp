.setcpu "65816"
.segment "CODE"
.org $98F1
map_control_0d98f1:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
