.setcpu "65816"
.segment "CODE"
.org $1AD4
map_control_0c1ad4:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
