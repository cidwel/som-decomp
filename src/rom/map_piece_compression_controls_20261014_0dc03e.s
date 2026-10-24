.setcpu "65816"
.segment "CODE"
.org $C03E
map_control_0dc03e:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
