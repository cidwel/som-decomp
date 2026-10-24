.setcpu "65816"
.segment "CODE"
.org $640B
map_control_0d640b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
