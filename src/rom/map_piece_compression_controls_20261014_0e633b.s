.setcpu "65816"
.segment "CODE"
.org $633B
map_control_0e633b:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
