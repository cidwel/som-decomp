.setcpu "65816"
.segment "CODE"
.org $CA7E
map_control_0eca7e:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
