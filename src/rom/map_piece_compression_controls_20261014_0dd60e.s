.setcpu "65816"
.segment "CODE"
.org $D60E
map_control_0dd60e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
