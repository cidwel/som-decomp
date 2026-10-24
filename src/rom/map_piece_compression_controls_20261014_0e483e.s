.setcpu "65816"
.segment "CODE"
.org $483E
map_control_0e483e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
