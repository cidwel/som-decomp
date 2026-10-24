.setcpu "65816"
.segment "CODE"
.org $CA04
map_control_0eca04:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
