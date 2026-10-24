.setcpu "65816"
.segment "CODE"
.org $0BE7
map_control_0f0be7:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
