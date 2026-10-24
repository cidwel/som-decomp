.setcpu "65816"
.segment "CODE"
.org $AB32
map_control_0fab32:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
