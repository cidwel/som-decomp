.setcpu "65816"
.segment "CODE"
.org $6AA8
map_control_0e6aa8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
