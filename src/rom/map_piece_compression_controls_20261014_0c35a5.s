.setcpu "65816"
.segment "CODE"
.org $35A5
map_control_0c35a5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
