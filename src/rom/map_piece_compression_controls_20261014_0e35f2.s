.setcpu "65816"
.segment "CODE"
.org $35F2
map_control_0e35f2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
