.setcpu "65816"
.segment "CODE"
.org $7FA0
map_control_0d7fa0:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
