.setcpu "65816"
.segment "CODE"
.org $CF33
map_control_0fcf33:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
