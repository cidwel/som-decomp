.setcpu "65816"
.segment "CODE"
.org $628D
map_control_0d628d:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
