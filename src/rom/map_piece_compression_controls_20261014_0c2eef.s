.setcpu "65816"
.segment "CODE"
.org $2EEF
map_control_0c2eef:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
