.setcpu "65816"
.segment "CODE"
.org $0FB7
map_control_0d0fb7:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
