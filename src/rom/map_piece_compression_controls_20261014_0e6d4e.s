.setcpu "65816"
.segment "CODE"
.org $6D4E
map_control_0e6d4e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
