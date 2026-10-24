.setcpu "65816"
.segment "CODE"
.org $35CE
map_control_0e35ce:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
