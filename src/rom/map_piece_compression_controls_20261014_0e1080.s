.setcpu "65816"
.segment "CODE"
.org $1080
map_control_0e1080:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
