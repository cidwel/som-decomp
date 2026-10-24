.setcpu "65816"
.segment "CODE"
.org $824E
map_control_0d824e:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
