.setcpu "65816"
.segment "CODE"
.org $7C47
map_control_0d7c47:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
