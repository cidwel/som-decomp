.setcpu "65816"
.segment "CODE"
.org $CA4E
map_control_0eca4e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
