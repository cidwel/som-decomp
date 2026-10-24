.setcpu "65816"
.segment "CODE"
.org $AD80
map_control_0fad80:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
